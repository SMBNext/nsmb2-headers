/*
*   GCC generates a table for us with function pointers that initialize global object. As we config
*   our linker to "bare metal" we need to implement this function on our own. We just have to add
*   correct symbols to our linker script and we have to insert a hook to this of course.
*/        

typedef void (*InitFunc)(void);
extern InitFunc __init_array_start;
extern InitFunc __init_array_end;

void static_init()
{
    for (InitFunc* p = &__init_array_start; p < &__init_array_end; p++)
        (*p)();
}


/*
*   This function registers global objects in C++. On program exit dtors are then called for these.
*   NSMB2 should have one but at the expected position there is just a NOP. Unless we do something
*   very memory critical just ignoring these should work out for now.
*   Just keep in mind that your static variables might not be destructed for now.
*/
void __aeabi_atexit(void* object, void (*dtor)(void* this), void* handle) { }

unsigned int __dso_handle = 0xDEADC0DE;


/*
*   Just like global objects, NSMB2 also does not destruct local static variables.
*/
void __cxa_guard_release(int* guardObject) { }
