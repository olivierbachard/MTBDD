/* mtbdd.C */

#include <jni.h>
#include "mtbdd.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "cudd.h"
#include "util.h"
#include "cuddInt.h"

//------------------------------------------------------------------------------

static DdManager *manager;

//-----------------------------------------------------------------------------

using namespace std;

void toDot(DdManager *manager, DdNode **outputs);

char* strToChar(string str)
{

    // créer le buffer pour copier la chaîne
    size_t size = str.size() + 1;
    char * buffer = new char[ size ];
    // copier la chaîne
    strncpy( buffer, str.c_str(), size );
    return buffer;
}

JNIEXPORT void JNICALL Java_Mtbdd_initialisation (JNIEnv *, jobject) {

	cout<<"Cudd init"<<endl;
	manager = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0);
}

JNIEXPORT void JNICALL Java_Mtbdd_affiche (JNIEnv *, jobject) {
   cout<<"Depuis code C++ \n   ... j'affiche ...\n   COUCOU"<<endl;
}

JNIEXPORT void JNICALL Java_Mtbdd_test (JNIEnv *, jobject) {

	cout << "fonction test" << endl;
	DdNode *x0 = Cudd_bddIthVar(manager, 0);
	DdNode *x1 = Cudd_bddIthVar(manager, 0);

	/*DdNode *and1 = Cudd_bddAnd(manager, x0, Cudd_Not(x1));
	Cudd_Ref(and1);

	DdNode *and2 = Cudd_bddAnd(manager, Cudd_Not(x0), x1);
	Cudd_Ref(and2);

	DdNode *sum = Cudd_bddOr(manager, and1, and2);
	Cudd_Ref(sum);

	Cudd_RecursiveDeref(manager, and1);
	Cudd_RecursiveDeref(manager, and2);

	DdNode *carry = Cudd_bddAnd(manager, x0, x1);
	Cudd_Ref(carry);*/

	DdNode **outputs = new DdNode*[2];
	outputs[0] = x0;
	outputs[1] = x1;

	/*cout << "output0:" << sum->index << endl;
	cout << "output1:" <<  carry->index << endl;
	cout << "output1:" <<  sum->type.value << endl;
	cout << "output1:" <<  carry->type.value << endl;*/
	cout << "ok" << endl;

	toDot(manager, outputs);

}

void toDot(DdManager *manager, DdNode **outputs) {

	char **inputNames = new char*[2];
	inputNames[0] = new char[3];
	inputNames[1] = new char[3];
	char *x1 = strToChar("x1");
	char *x2 = strToChar("x2");
	inputNames[0] = x1;
	inputNames[1] = x2;

	char **outputNames = new char*[2];
	outputNames[0] = new char[4];
	outputNames[1] = new char[6];
	strcpy(outputNames[0],"sum");
	strcpy(outputNames[1],"carry");

	FILE *f = fopen("./half_adder.dot","w");

	Cudd_DumpDot(manager, 2, outputs, inputNames, outputNames, f);
}



