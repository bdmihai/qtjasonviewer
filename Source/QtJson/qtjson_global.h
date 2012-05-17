#ifndef QTJSON_GLOBAL_H
#define QTJSON_GLOBAL_H

#ifdef QTJSON_LIB
# define QTJSON_EXPORT Q_DECL_EXPORT
#else
# define QTJSON_EXPORT Q_DECL_IMPORT
#endif

#endif // QTJSON_GLOBAL_H
