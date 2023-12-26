/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.10u-20030105-1905
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIGPYTHON
/***********************************************************************
 * common.swg
 *
 *     This file contains generic SWIG runtime support for pointer
 *     type checking as well as a few commonly used macros to control
 *     external linkage.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 *
 * Copyright (c) 1999-2000, The University of Chicago
 * 
 * This file may be freely redistributed without license or fee provided
 * this copyright message remains intact.
 ************************************************************************/

#include <string.h>

#if defined(_WIN32) || defined(__WIN32__)
#       if defined(_MSC_VER)
#               if defined(STATIC_LINKED)
#                       define SWIGEXPORT(a) a
#               else
#                       define SWIGEXPORT(a) __declspec(dllexport) a
#               endif
#       else
#               if defined(__BORLANDC__)
#                       define SWIGEXPORT(a) a _export
#               else
#                       define SWIGEXPORT(a) a
#       endif
#endif
#else
#       define SWIGEXPORT(a) a
#endif

#ifdef SWIG_GLOBAL
#define SWIGRUNTIME(a) SWIGEXPORT(a)
#else
#define SWIGRUNTIME(a) static a
#endif



#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *);

typedef struct swig_type_info {
  const char             *name;                 
  swig_converter_func     converter;
  const char             *str;
  struct swig_type_info  *next;
  struct swig_type_info  *prev;
  void                   *clientdata;	
} swig_type_info;

#ifdef SWIG_NOINCLUDE
SWIGEXPORT(swig_type_info *) SWIG_TypeRegister(swig_type_info *);
SWIGEXPORT(swig_type_info *) SWIG_TypeCheck(char *c, swig_type_info *);
SWIGEXPORT(void *) SWIG_TypeCast(swig_type_info *, void *);
SWIGEXPORT(swig_type_info *) SWIG_TypeQuery(const char *);
SWIGEXPORT(void) SWIG_TypeClientData(swig_type_info *, void *);
#else

static swig_type_info *swig_type_list = 0;

/* Register a type mapping with the type-checking */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeRegister(swig_type_info *ti)
{
  swig_type_info *tc, *head, *ret, *next;
  /* Check to see if this type has already been registered */
  tc = swig_type_list;
  while (tc) {
    if (strcmp(tc->name, ti->name) == 0) {
      /* Already exists in the table.  Just add additional types to the list */
      head = tc;
      next = tc->next;
      goto l1;
    }
    tc = tc->prev;
  }
  head = ti;
  next = 0;

  /* Place in list */
  ti->prev = swig_type_list;
  swig_type_list = ti;

  /* Build linked lists */
 l1:
  ret = head;
  tc = ti + 1;
  /* Patch up the rest of the links */
  while (tc->name) {
    head->next = tc;
    tc->prev = head;
    head = tc;
    tc++;
  }
  head->next = next;
  return ret;
}

/* Check the typename */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeCheck(char *c, swig_type_info *ty)
{
  swig_type_info *s;
  if (!ty) return 0;        /* Void pointer */
  s = ty->next;             /* First element always just a name */
  while (s) {
    if (strcmp(s->name,c) == 0) {
      if (s == ty->next) return s;
      /* Move s to the top of the linked list */
      s->prev->next = s->next;
      if (s->next) {
	s->next->prev = s->prev;
      }
      /* Insert s as second element in the list */
      s->next = ty->next;
      if (ty->next) ty->next->prev = s;
      ty->next = s;
      return s;
    }
    s = s->next;
  }
  return 0;
}

/* Cast a pointer (needed for C++ inheritance */
SWIGRUNTIME(void *) 
SWIG_TypeCast(swig_type_info *ty, void *ptr) 
{
  if ((!ty) || (!ty->converter)) return ptr;
  return (*ty->converter)(ptr);
}

/* Search for a swig_type_info structure */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeQuery(const char *name) {
  swig_type_info *ty = swig_type_list;
  while (ty) {
    if (ty->str && (strcmp(name,ty->str) == 0)) return ty;
    if (ty->name && (strcmp(name,ty->name) == 0)) return ty;
    ty = ty->prev;
  }
  return 0;
}

/* Set the clientdata field for a type */
SWIGRUNTIME(void)
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_type_info *tc, *equiv;
  if (ti->clientdata) return;
  ti->clientdata = clientdata;
  equiv = ti->next;
  while (equiv) {
    if (!equiv->converter) {
      tc = swig_type_list;
      while (tc) {
	if ((strcmp(tc->name, equiv->name) == 0))
	  SWIG_TypeClientData(tc,clientdata);
	tc = tc->prev;
      }
    }
    equiv = equiv->next;
  }
}
#endif

#ifdef __cplusplus
}
#endif




/***********************************************************************
 * python.swg
 *
 *     This file contains the runtime support for Python modules
 *     and includes code for managing global variables and pointer
 *     type checking.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 ************************************************************************/

#include <stdlib.h>
#include "Python.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SWIG_PY_INT     1
#define SWIG_PY_FLOAT   2
#define SWIG_PY_STRING  3
#define SWIG_PY_POINTER 4
#define SWIG_PY_BINARY  5

/* Constant information structure */
typedef struct swig_const_info {
    int type;
    char *name;
    long lvalue;
    double dvalue;
    void   *pvalue;
    swig_type_info **ptype;
} swig_const_info;

#ifdef SWIG_NOINCLUDE

SWIGEXPORT(PyObject *)        SWIG_newvarlink();
SWIGEXPORT(void)              SWIG_addvarlink(PyObject *, char *, PyObject *(*)(void), int (*)(PyObject *));
SWIGEXPORT(int)               SWIG_ConvertPtr(PyObject *, void **, swig_type_info *, int);
SWIGEXPORT(int)               SWIG_ConvertPacked(PyObject *, void *, int sz, swig_type_info *, int);
SWIGEXPORT(char *)            SWIG_PackData(char *c, void *, int);
SWIGEXPORT(char *)            SWIG_UnpackData(char *c, void *, int);
SWIGEXPORT(PyObject *)        SWIG_NewPointerObj(void *, swig_type_info *,int own);
SWIGEXPORT(PyObject *)        SWIG_NewPackedObj(void *, int sz, swig_type_info *);
SWIGEXPORT(void)              SWIG_InstallConstants(PyObject *d, swig_const_info constants[]);
SWIGEXPORT(PyObject *)        SWIG_MakeShadow(PyObject *robj, swig_type_info *type, int own);
#else

/* -----------------------------------------------------------------------------
 * global variable support code.
 * ----------------------------------------------------------------------------- */

typedef struct swig_globalvar {   
  char       *name;                  /* Name of global variable */
  PyObject *(*get_attr)(void);       /* Return the current value */
  int       (*set_attr)(PyObject *); /* Set the value */
  struct swig_globalvar *next;
} swig_globalvar;

typedef struct swig_varlinkobject {
  PyObject_HEAD
  swig_globalvar *vars;
} swig_varlinkobject;

static PyObject *
swig_varlink_repr(swig_varlinkobject *v) {
  v = v;
  return PyString_FromString("<Global variables>");
}

static int
swig_varlink_print(swig_varlinkobject *v, FILE *fp, int flags) {
  swig_globalvar  *var;
  flags = flags;
  fprintf(fp,"Global variables { ");
  for (var = v->vars; var; var=var->next) {
    fprintf(fp,"%s", var->name);
    if (var->next) fprintf(fp,", ");
  }
  fprintf(fp," }\n");
  return 0;
}

static PyObject *
swig_varlink_getattr(swig_varlinkobject *v, char *n) {
  swig_globalvar *var = v->vars;
  while (var) {
    if (strcmp(var->name,n) == 0) {
      return (*var->get_attr)();
    }
    var = var->next;
  }
  PyErr_SetString(PyExc_NameError,"Unknown C global variable");
  return NULL;
}

static int
swig_varlink_setattr(swig_varlinkobject *v, char *n, PyObject *p) {
  swig_globalvar *var = v->vars;
  while (var) {
    if (strcmp(var->name,n) == 0) {
      return (*var->set_attr)(p);
    }
    var = var->next;
  }
  PyErr_SetString(PyExc_NameError,"Unknown C global variable");
  return 1;
}

statichere PyTypeObject varlinktype = {
  PyObject_HEAD_INIT(0)              
  0,
  (char *)"swigvarlink",                      /* Type name    */
  sizeof(swig_varlinkobject),         /* Basic size   */
  0,                                  /* Itemsize     */
  0,                                  /* Deallocator  */ 
  (printfunc) swig_varlink_print,     /* Print        */
  (getattrfunc) swig_varlink_getattr, /* get attr     */
  (setattrfunc) swig_varlink_setattr, /* Set attr     */
  0,                                  /* tp_compare   */
  (reprfunc) swig_varlink_repr,       /* tp_repr      */    
  0,                                  /* tp_as_number */
  0,                                  /* tp_as_mapping*/
  0,                                  /* tp_hash      */
};

/* Create a variable linking object for use later */
SWIGRUNTIME(PyObject *)
SWIG_newvarlink(void) {
  swig_varlinkobject *result = 0;
  result = PyMem_NEW(swig_varlinkobject,1);
  varlinktype.ob_type = &PyType_Type;    /* Patch varlinktype into a PyType */
  result->ob_type = &varlinktype;
  result->vars = 0;
  result->ob_refcnt = 0;
  Py_XINCREF((PyObject *) result);
  return ((PyObject*) result);
}

SWIGRUNTIME(void)
SWIG_addvarlink(PyObject *p, char *name,
	   PyObject *(*get_attr)(void), int (*set_attr)(PyObject *p)) {
  swig_varlinkobject *v;
  swig_globalvar *gv;
  v= (swig_varlinkobject *) p;
  gv = (swig_globalvar *) malloc(sizeof(swig_globalvar));
  gv->name = (char *) malloc(strlen(name)+1);
  strcpy(gv->name,name);
  gv->get_attr = get_attr;
  gv->set_attr = set_attr;
  gv->next = v->vars;
  v->vars = gv;
}

/* Pack binary data into a string */
SWIGRUNTIME(char *)
SWIG_PackData(char *c, void *ptr, int sz) {
  static char hex[17] = "0123456789abcdef";
  int i;
  unsigned char *u = (unsigned char *) ptr;
  register unsigned char uu;
  for (i = 0; i < sz; i++,u++) {
    uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/* Unpack binary data from a string */
SWIGRUNTIME(char *)
SWIG_UnpackData(char *c, void *ptr, int sz) {
  register unsigned char uu;
  register int d;
  unsigned char *u = (unsigned char *) ptr;
  int i;
  for (i = 0; i < sz; i++, u++) {
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu = ((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = ((d - ('a'-10)) << 4);
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (d - ('a'-10));
    *u = uu;
  }
  return c;
}

/* Convert a pointer value */
SWIGRUNTIME(int)
SWIG_ConvertPtr(PyObject *obj, void **ptr, swig_type_info *ty, int flags) {
  swig_type_info *tc;
  char  *c;
  static PyObject *SWIG_this = 0;
  int    newref = 0;

  if (!obj) return 0;
  if (obj == Py_None) {
    *ptr = 0;
    return 0;
  }
#ifdef SWIG_COBJECT_TYPES
  if (!(PyCObject_Check(obj))) {
    if (!SWIG_this)
      SWIG_this = PyString_InternFromString("this");
    obj = PyObject_GetAttr(obj,SWIG_this);
    newref = 1;
    if (!obj) goto type_error;
    if (!PyCObject_Check(obj)) {
      Py_DECREF(obj);
      goto type_error;
    }
  } 
  *ptr = PyCObject_AsVoidPtr(obj);
  c = (char *) PyCObject_GetDesc(obj);
  if (newref) Py_DECREF(obj);
  goto cobject;
#else
  if (!(PyString_Check(obj))) {
    if (!SWIG_this)
      SWIG_this = PyString_InternFromString("this");
    obj = PyObject_GetAttr(obj,SWIG_this);
    newref = 1;
    if (!obj) goto type_error;
    if (!PyString_Check(obj)) {
      Py_DECREF(obj);
      goto type_error;
    }
  } 
  c = PyString_AsString(obj);
  /* Pointer values must start with leading underscore */
  if (*c != '_') {
    *ptr = (void *) 0;
    if (strcmp(c,"NULL") == 0) {
      if (newref) Py_DECREF(obj);
      return 0;
    } else {
      if (newref) Py_DECREF(obj);
      goto type_error;
    }
  }
  c++;
  c = SWIG_UnpackData(c,ptr,sizeof(void *));
  if (newref) Py_DECREF(obj);
#endif

#ifdef SWIG_COBJECT_TYPES
cobject:
#endif

  if (ty) {
    tc = SWIG_TypeCheck(c,ty);
    if (!tc) goto type_error;
    *ptr = SWIG_TypeCast(tc,(void*) *ptr);
  }
  return 0;

type_error:
  if (flags) {
    if (ty) {
      char *temp = (char *) malloc(64+strlen(ty->name));
      sprintf(temp,"Type error. Expected %s", ty->name);
      PyErr_SetString(PyExc_TypeError, temp);
      free((char *) temp);
    } else {
      PyErr_SetString(PyExc_TypeError,"Expected a pointer");
    }
  }
  return -1;
}

/* Convert a packed value value */
SWIGRUNTIME(int)
SWIG_ConvertPacked(PyObject *obj, void *ptr, int sz, swig_type_info *ty, int flags) {
  swig_type_info *tc;
  char  *c;

  if ((!obj) || (!PyString_Check(obj))) goto type_error;
  c = PyString_AsString(obj);
  /* Pointer values must start with leading underscore */
  if (*c != '_') goto type_error;
  c++;
  c = SWIG_UnpackData(c,ptr,sz);
  if (ty) {
    tc = SWIG_TypeCheck(c,ty);
    if (!tc) goto type_error;
  }
  return 0;

type_error:

  if (flags) {
    if (ty) {
      char *temp = (char *) malloc(64+strlen(ty->name));
      sprintf(temp,"Type error. Expected %s", ty->name);
      PyErr_SetString(PyExc_TypeError, temp);
      free((char *) temp);
    } else {
      PyErr_SetString(PyExc_TypeError,"Expected a pointer");
    }
  }
  return -1;
}

/* Create a new pointer object */
SWIGRUNTIME(PyObject *)
SWIG_NewPointerObj(void *ptr, swig_type_info *type, int own) {
  PyObject *robj;
  if (!ptr) {
    Py_INCREF(Py_None);
    return Py_None;
  }
#ifdef SWIG_COBJECT_TYPES
  robj = PyCObject_FromVoidPtrAndDesc((void *) ptr, (char *) type->name, NULL);
#else
  {
    char result[512];
    char *r = result;
    *(r++) = '_';
    r = SWIG_PackData(r,&ptr,sizeof(void *));
    strcpy(r,type->name);
    robj = PyString_FromString(result);
  }
#endif
  if (!robj || (robj == Py_None)) return robj;
  if (type->clientdata) {
    PyObject *inst;
    PyObject *args = Py_BuildValue((char*)"(O)", robj);
    Py_DECREF(robj);
    inst = PyObject_CallObject((PyObject *) type->clientdata, args);
    Py_DECREF(args);
    if (own) {
      PyObject *n = PyInt_FromLong(1);
      PyObject_SetAttrString(inst,(char*)"thisown",n);
      Py_DECREF(n);
    }
    robj = inst;
  }
  return robj;
}

SWIGRUNTIME(PyObject *)
SWIG_MakeShadow(PyObject *robj, swig_type_info *type, int own) {
  if (!robj || (robj == Py_None)) return robj;
  if (type->clientdata) {
    PyInstanceObject *inst;
    inst = PyObject_NEW(PyInstanceObject, &PyInstance_Type);
    if (!inst) return robj;
    inst->in_dict = PyDict_New();
    inst->in_class = (PyClassObject *) type->clientdata;
    Py_INCREF(inst->in_class);
    PyObject_SetAttrString((PyObject *)inst,(char*)"this",robj);
    Py_DECREF(robj);
    if (own) {
      PyObject *n = PyInt_FromLong(1);
      PyObject_SetAttrString((PyObject *)inst,(char*)"thisown",n);
      Py_DECREF(n);
    }
    robj = (PyObject *) inst;
    Py_INCREF(robj);
  }
  return robj;
}

SWIGRUNTIME(PyObject *)
SWIG_NewPackedObj(void *ptr, int sz, swig_type_info *type) {
  char result[1024];
  char *r = result;
  if ((2*sz + 1 + strlen(type->name)) > 1000) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,ptr,sz);
  strcpy(r,type->name);
  return PyString_FromString(result);
}

/* Install Constants */
SWIGRUNTIME(void)
SWIG_InstallConstants(PyObject *d, swig_const_info constants[]) {
  int i;
  PyObject *obj;
  for (i = 0; constants[i].type; i++) {
    switch(constants[i].type) {
    case SWIG_PY_INT:
      obj = PyInt_FromLong(constants[i].lvalue);
      break;
    case SWIG_PY_FLOAT:
      obj = PyFloat_FromDouble(constants[i].dvalue);
      break;
    case SWIG_PY_STRING:
      obj = PyString_FromString((char *) constants[i].pvalue);
      break;
    case SWIG_PY_POINTER:
      obj = SWIG_NewPointerObj(constants[i].pvalue, *(constants[i]).ptype,0);
      break;
    case SWIG_PY_BINARY:
      obj = SWIG_NewPackedObj(constants[i].pvalue, constants[i].lvalue, *(constants[i].ptype));
      break;
    default:
      obj = 0;
      break;
    }
    if (obj) {
      PyDict_SetItemString(d,constants[i].name,obj);
      Py_DECREF(obj);
    }
  }
}

#endif

#ifdef __cplusplus
}
#endif








/* -------- TYPES TABLE (BEGIN) -------- */

#define  SWIGTYPE_p_PSMem swig_types[0] 
static swig_type_info *swig_types[2];

/* -------- TYPES TABLE (END) -------- */


/*-----------------------------------------------
              @(target):= PSMemc.so
  ------------------------------------------------*/
#define SWIG_init    initPSMemc

#define SWIG_name    "PSMemc"

#include "Include/Main.h"


typedef unsigned long UINT32;

#ifdef __cplusplus
extern "C" {
#endif
static PyObject *_wrap_new_PSMem(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    char *arg1 ;
    PSMem *result;
    
    if(!PyArg_ParseTuple(args,(char *)"s:new_PSMem",&arg1)) return NULL;
    result = (PSMem *)new PSMem(arg1);
    
    resultobj = SWIG_NewPointerObj((void *) result, SWIGTYPE_p_PSMem, 1);
    return resultobj;
}


static PyObject *_wrap_delete_PSMem(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:delete_PSMem",&obj0)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    delete arg1;
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadByte(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:PSMem_LoadByte",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (UINT32 )(arg1)->LoadByte(arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadByteUnsigned(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:PSMem_LoadByteUnsigned",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (UINT32 )(arg1)->LoadByteUnsigned(arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadHalfword(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:PSMem_LoadHalfword",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (UINT32 )(arg1)->LoadHalfword(arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadHalfwordUnsigned(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:PSMem_LoadHalfwordUnsigned",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (UINT32 )(arg1)->LoadHalfwordUnsigned(arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadWord(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:PSMem_LoadWord",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (UINT32 )(arg1)->LoadWord(arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadWordLeft(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_LoadWordLeft",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->LoadWordLeft(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadWordRight(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_LoadWordRight",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->LoadWordRight(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadWordToCOP0(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:PSMem_LoadWordToCOP0",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (UINT32 )(arg1)->LoadWordToCOP0(arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_PSMem_LoadWordToCOP2(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 result;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OO:PSMem_LoadWordToCOP2",&obj0,&obj1)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    result = (UINT32 )(arg1)->LoadWordToCOP2(arg2);
    
    resultobj = PyInt_FromLong((long)result);
    return resultobj;
}


static PyObject *_wrap_PSMem_StoreByte(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_StoreByte",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->StoreByte(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_StoreHalfword(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_StoreHalfword",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->StoreHalfword(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_StoreWord(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_StoreWord",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->StoreWord(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_StoreWordLeft(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_StoreWordLeft",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->StoreWordLeft(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_StoreWordRight(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_StoreWordRight",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->StoreWordRight(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_StoreWordFromCOP0(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_StoreWordFromCOP0",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->StoreWordFromCOP0(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_StoreWordFromCOP2(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOO:PSMem_StoreWordFromCOP2",&obj0,&obj1,&obj2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    (arg1)->StoreWordFromCOP2(arg2,arg3);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_Copy(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    UINT32 arg2 ;
    UINT32 arg3 ;
    UINT32 arg4 ;
    PyObject * obj0  = 0 ;
    PyObject * obj1  = 0 ;
    PyObject * obj2  = 0 ;
    PyObject * obj3  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OOOO:PSMem_Copy",&obj0,&obj1,&obj2,&obj3)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg2 = (UINT32 ) PyInt_AsLong(obj1);
    if (PyErr_Occurred()) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    arg4 = (UINT32 ) PyInt_AsLong(obj3);
    if (PyErr_Occurred()) return NULL;
    (arg1)->Copy(arg2,arg3,arg4);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_ImportBIOS(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    char *arg2 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Os:PSMem_ImportBIOS",&obj0,&arg2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    (arg1)->ImportBIOS((char const *)arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_ImportEXE(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    char *arg2 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Os:PSMem_ImportEXE",&obj0,&arg2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    (arg1)->ImportEXE((char const *)arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_Export(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    char *arg2 ;
    UINT32 arg3 ;
    UINT32 arg4 ;
    PyObject * obj0  = 0 ;
    PyObject * obj2  = 0 ;
    PyObject * obj3  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"OsOO:PSMem_Export",&obj0,&arg2,&obj2,&obj3)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    arg3 = (UINT32 ) PyInt_AsLong(obj2);
    if (PyErr_Occurred()) return NULL;
    arg4 = (UINT32 ) PyInt_AsLong(obj3);
    if (PyErr_Occurred()) return NULL;
    (arg1)->Export((char const *)arg2,arg3,arg4);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_Backup(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    char *arg2 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Os:PSMem_Backup",&obj0,&arg2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    (arg1)->Backup((char const *)arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_Restore(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    char *arg2 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"Os:PSMem_Restore",&obj0,&arg2)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    (arg1)->Restore((char const *)arg2);
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject *_wrap_PSMem_ResetMem(PyObject *self, PyObject *args) {
    PyObject *resultobj;
    PSMem *arg1 ;
    PyObject * obj0  = 0 ;
    
    if(!PyArg_ParseTuple(args,(char *)"O:PSMem_ResetMem",&obj0)) return NULL;
    if ((SWIG_ConvertPtr(obj0,(void **) &arg1, SWIGTYPE_p_PSMem,1)) == -1) return NULL;
    (arg1)->ResetMem();
    
    Py_INCREF(Py_None); resultobj = Py_None;
    return resultobj;
}


static PyObject * PSMem_swigregister(PyObject *self, PyObject *args) {
    PyObject *obj;
    if (!PyArg_ParseTuple(args,(char*)"O", &obj)) return NULL;
    SWIG_TypeClientData(SWIGTYPE_p_PSMem, obj);
    Py_INCREF(obj);
    return Py_BuildValue((char *)"");
}
static PyMethodDef SwigMethods[] = {
	 { (char *)"new_PSMem", _wrap_new_PSMem, METH_VARARGS },
	 { (char *)"delete_PSMem", _wrap_delete_PSMem, METH_VARARGS },
	 { (char *)"PSMem_LoadByte", _wrap_PSMem_LoadByte, METH_VARARGS },
	 { (char *)"PSMem_LoadByteUnsigned", _wrap_PSMem_LoadByteUnsigned, METH_VARARGS },
	 { (char *)"PSMem_LoadHalfword", _wrap_PSMem_LoadHalfword, METH_VARARGS },
	 { (char *)"PSMem_LoadHalfwordUnsigned", _wrap_PSMem_LoadHalfwordUnsigned, METH_VARARGS },
	 { (char *)"PSMem_LoadWord", _wrap_PSMem_LoadWord, METH_VARARGS },
	 { (char *)"PSMem_LoadWordLeft", _wrap_PSMem_LoadWordLeft, METH_VARARGS },
	 { (char *)"PSMem_LoadWordRight", _wrap_PSMem_LoadWordRight, METH_VARARGS },
	 { (char *)"PSMem_LoadWordToCOP0", _wrap_PSMem_LoadWordToCOP0, METH_VARARGS },
	 { (char *)"PSMem_LoadWordToCOP2", _wrap_PSMem_LoadWordToCOP2, METH_VARARGS },
	 { (char *)"PSMem_StoreByte", _wrap_PSMem_StoreByte, METH_VARARGS },
	 { (char *)"PSMem_StoreHalfword", _wrap_PSMem_StoreHalfword, METH_VARARGS },
	 { (char *)"PSMem_StoreWord", _wrap_PSMem_StoreWord, METH_VARARGS },
	 { (char *)"PSMem_StoreWordLeft", _wrap_PSMem_StoreWordLeft, METH_VARARGS },
	 { (char *)"PSMem_StoreWordRight", _wrap_PSMem_StoreWordRight, METH_VARARGS },
	 { (char *)"PSMem_StoreWordFromCOP0", _wrap_PSMem_StoreWordFromCOP0, METH_VARARGS },
	 { (char *)"PSMem_StoreWordFromCOP2", _wrap_PSMem_StoreWordFromCOP2, METH_VARARGS },
	 { (char *)"PSMem_Copy", _wrap_PSMem_Copy, METH_VARARGS },
	 { (char *)"PSMem_ImportBIOS", _wrap_PSMem_ImportBIOS, METH_VARARGS },
	 { (char *)"PSMem_ImportEXE", _wrap_PSMem_ImportEXE, METH_VARARGS },
	 { (char *)"PSMem_Export", _wrap_PSMem_Export, METH_VARARGS },
	 { (char *)"PSMem_Backup", _wrap_PSMem_Backup, METH_VARARGS },
	 { (char *)"PSMem_Restore", _wrap_PSMem_Restore, METH_VARARGS },
	 { (char *)"PSMem_ResetMem", _wrap_PSMem_ResetMem, METH_VARARGS },
	 { (char *)"PSMem_swigregister", PSMem_swigregister, METH_VARARGS },
	 { NULL, NULL }
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static swig_type_info _swigt__p_PSMem[] = {{"_p_PSMem", 0, "PSMem *"},{"_p_PSMem"},{0}};

static swig_type_info *swig_types_initial[] = {
_swigt__p_PSMem, 
0
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

static swig_const_info swig_const_table[] = {
{ SWIG_PY_INT,     (char *)"MemSize", (long) 0x00292400, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakePPStart", (long) 0x1F000000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakePPLast", (long) 0x1F00FFFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeSPStart", (long) 0x1F800000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeSPLast", (long) 0x1F8003FF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeHRStart", (long) 0x1F801000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeHRLast", (long) 0x1F802FFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeM1Start", (long) 0x80000000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeM1Last", (long) 0x801FFFFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeM2Start", (long) 0xA0000000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeM2Last", (long) 0xA01FFFFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeBStart", (long) 0xBFC00000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"FakeBLast", (long) 0xBFC7FFFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealKStart", (long) 0x00000000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealKLast", (long) 0x0000FFFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealUStart", (long) 0x00010000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealULast", (long) 0x001FFFFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealPPStart", (long) 0x00200000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealPPLast", (long) 0x0020FFFF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealSPStart", (long) 0x00210000, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealSPLast", (long) 0x002103FF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealHRStart", (long) 0x00210400, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealHRLast", (long) 0x002123FF, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealBStart", (long) 0x00212400, 0, 0, 0},
{ SWIG_PY_INT,     (char *)"RealBLast", (long) 0x002923FF, 0, 0, 0},
{0}};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT(void) SWIG_init(void) {
    static PyObject *SWIG_globals = 0;
    PyObject *m, *d;
    int       i;
    SWIG_globals = SWIG_newvarlink();
    m = Py_InitModule((char *) SWIG_name, SwigMethods);
    d = PyModule_GetDict(m);
    
    for (i = 0; swig_types_initial[i]; i++) {
        swig_types[i] = SWIG_TypeRegister(swig_types_initial[i]);
    }
    SWIG_InstallConstants(d,swig_const_table);
    
}

