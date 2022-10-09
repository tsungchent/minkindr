#ifndef MINKINDR_MINIMAL_MACROS_H
#define MINKINDR_MINIMAL_MACROS_H

#if __GNUC__
#define attribute_deprecated __attribute__((deprecated))
#elif defined(_MSC_VER)
#define attribute_deprecated __declspec(deprecated)
#else
#define attribute_deprecated
#endif


#endif