/*    Common Mistakes when using a pointer to funciton    */

/* Common mistakes

Inappropriate Declaration of a Pointer to a Function
----------------------------------------------------

int func1();        // returns an int type
int *func2();       // returns a pointer to int type    
int *ptrFunc();     // returns a pointer to int type
int (*ptrFunc)();   // returns a pointer to a function (inside main())

*/