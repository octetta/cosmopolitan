#ifndef Py_STRUCTSEQ_H
#define Py_STRUCTSEQ_H
COSMOPOLITAN_C_START_
/* clang-format off */

typedef struct PyStructSequence_Field {
    char *name;
    char *doc;
} PyStructSequence_Field;

typedef struct PyStructSequence_Desc {
    char *name;
    char *doc;
    struct PyStructSequence_Field *fields;
    int n_in_sequence;
} PyStructSequence_Desc;

extern char* PyStructSequence_UnnamedField;

#ifndef Py_LIMITED_API
PyAPI_FUNC(void) PyStructSequence_InitType(PyTypeObject *type,
                                           PyStructSequence_Desc *desc);
PyAPI_FUNC(int) PyStructSequence_InitType2(PyTypeObject *type,
                                           PyStructSequence_Desc *desc);
#endif
PyAPI_FUNC(PyTypeObject*) PyStructSequence_NewType(PyStructSequence_Desc *desc);

PyAPI_FUNC(PyObject *) PyStructSequence_New(PyTypeObject* type);

#ifndef Py_LIMITED_API
typedef PyTupleObject PyStructSequence;

/* Macro, *only* to be used to fill in brand new objects */
#define PyStructSequence_SET_ITEM(op, i, v) PyTuple_SET_ITEM(op, i, v)

#define PyStructSequence_GET_ITEM(op, i) PyTuple_GET_ITEM(op, i)
#endif

PyAPI_FUNC(void) PyStructSequence_SetItem(PyObject*, Py_ssize_t, PyObject*);
PyAPI_FUNC(PyObject*) PyStructSequence_GetItem(PyObject*, Py_ssize_t);

COSMOPOLITAN_C_END_
#endif /* !Py_STRUCTSEQ_H */
