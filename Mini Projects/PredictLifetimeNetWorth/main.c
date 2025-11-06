#include <stdio.h>
#include <math.h>

// --- Function prototypes ---
double update_debt(double debt_balance, double monthly_payment, double monthly_interest_rate, double extra_payment);
double update_investment(double investment, double monthly_return_rate, double monthly_contribution);
double update_salary(double current_salary, double yearly_increase, double inflation_rate);
double update_assets(double assets, double yearly_appreciation, double yearly_depreciation);
double calculate_net_worth(double assets, double stocks, double bonds, double debt);
double calculate_percentage(double part, double total);

int main() {
    // --- Inputs ---
    int age, years;
    double current_salary, yearly_increase, inflation_rate, invest_percent;
    double debt, debt_interest, monthly_payment, extra_payment;
    double stocks, stocks_interest, bonds, bonds_interest, assets;
    double assets_appreciation, assets_depreciation;

    printf("Enter your current age: ");
    scanf("%d", &age);

    printf("Enter number of years to simulate: ");
    scanf("%d", &years);

    printf("Enter current salary: ");
    scanf("%lf", &current_salary);

    printf("Enter expected yearly salary increase (%%): ");
    scanf("%lf", &yearly_increase);

    printf("Enter expected yearly inflation (%%): ");
    scanf("%lf", &inflation_rate);

    printf("Enter investment percentage of salary (%%): ");
    scanf("%lf", &invest_percent);

    printf("Enter total debt amount: ");
    scanf("%lf", &debt);

    printf("Enter yearly debt interest rate (%%): ");
    scanf("%lf", &debt_interest);

    printf("Enter monthly debt payment: ");
    scanf("%lf", &monthly_payment);

    printf("Enter extra debt payment per year: ");
    scanf("%lf", &extra_payment);

    printf("Enter current investments in stocks: ");
    scanf("%lf", &stocks);

    printf("Enter expected yearly return for stocks (%%): ");
    scanf("%lf", &stocks_interest);

    printf("Enter current investments in bonds: ");
    scanf("%lf", &bonds);

    printf("Enter expected yearly return for bonds (%%): ");
    scanf("%lf", &bonds_interest);

    printf("Enter hard assets value: ");
    scanf("%lf", &assets);

    printf("Enter yearly assets appreciation rate (%%): ");
    scanf("%lf", &assets_appreciation);

    printf("Enter yearly assets depreciation rate (%%): ");
    scanf("%lf", &assets_depreciation);

    // --- Convert percentages to decimals ---
    yearly_increase /= 100.0;
    inflation_rate /= 100.0;
    invest_percent /= 100.0;
    debt_interest /= 100.0;
    stocks_interest /= 100.0;
    bonds_interest /= 100.0;
    assets_appreciation /= 100.0;
    assets_depreciation /= 100.0;

    double debt_balance = debt;

    printf("\n%-6s %-15s %-12s %-12s %-15s %-12s %-15s\n",
           "Age", "Net Worth", "Salary", "Stocks", "Stocks(%)", "Bonds", "Bonds(%)");

    for (int y = 0; y < years; y++) {
        // Monthly rates
        double monthly_debt_rate = debt_interest / 12.0;
        double monthly_stock_rate = pow(1 + stocks_interest, 1.0/12.0) - 1;
        double monthly_bond_rate = pow(1 + bonds_interest, 1.0/12.0) - 1;

        // Monthly contribution from salary
        double monthly_salary = current_salary / 12.0;
        double monthly_invest = monthly_salary * invest_percent;

        // --- Update investments monthly ---
        for (int m = 0; m < 12; m++) {
            // Split investment (70% stocks, 30% bonds)
            double stock_contrib = monthly_invest * 0.7;
            double bond_contrib = monthly_invest * 0.3;

            stocks = update_investment(stocks, monthly_stock_rate, stock_contrib);
            bonds = update_investment(bonds, monthly_bond_rate, bond_contrib);

            // Update debt monthly
            debt_balance = update_debt(debt_balance, monthly_payment, monthly_debt_rate, 0);
        }

        // Apply extra debt payment at year end
        debt_balance = update_debt(debt_balance, 0, 0, extra_payment);

        // Update salary with yearly increase & inflation
        current_salary = update_salary(current_salary, yearly_increase, inflation_rate);

        // Update assets with appreciation & depreciation
        assets = update_assets(assets, assets_appreciation, assets_depreciation);

        // Calculate net worth
        double net_worth = calculate_net_worth(assets, stocks, bonds, debt_balance);

        // Investment percentages
        double stock_pct = calculate_percentage(stocks, net_worth);
        double bond_pct = calculate_percentage(bonds, net_worth);

        printf("%-6d %-15.2f %-12.2f %-12.2f %-15.2f %-12.2f %-15.2f\n",
               age + y, net_worth, current_salary, stocks, stock_pct, bonds, bond_pct);
    }

    return 0;
}

// --- Function Definitions ---

// Update debt for one month (interest + payments)
double update_debt(double debt_balance, double monthly_payment, double monthly_interest_rate, double extra_payment) {
    debt_balance = debt_balance * (1 + monthly_interest_rate) - monthly_payment - extra_payment;
    if (debt_balance < 0) debt_balance = 0;
    return debt_balance;
}

// Update investment for one month (contribution + interest)
double update_investment(double investment, double monthly_return_rate, double monthly_contribution) {
    investment = investment * (1 + monthly_return_rate) + monthly_contribution;
    return investment;
}

// Update salary yearly with raise and inflation
double update_salary(double current_salary, double yearly_increase, double inflation_rate) {
    current_salary = current_salary * (1 + yearly_increase) * (1 + inflation_rate);
    return current_salary;
}

// Update assets yearly (appreciation & depreciation)
double update_assets(double assets, double yearly_appreciation, double yearly_depreciation) {
    assets = assets * (1 + yearly_appreciation - yearly_depreciation);
    return assets;
}

// Calculate net worth
double calculate_net_worth(double assets, double stocks, double bonds, double debt) {
    return assets + stocks + bonds - debt;
}

// Calculate percentage of net worth
double calculate_percentage(double part, double total) {
    if (total <= 0) return 0;
    return (part / total) * 100;
}
