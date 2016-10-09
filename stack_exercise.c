#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


int in_stack(DynArr * s,char tofind){
  /*
     Returns 1 if the element `tofind` is present in DynArr `s`, 0
     otherwise.  Upon returning `s` should have its elements in the
     same order as when the function is called. In other words, you
     may modify `s` but must return it to its original state

     You may only call the following funcitons

        DynArr *createDynArr(int cap);
        int isEmptyDynArr(DynArr *v);
        void pushDynArr(DynArr *v, TYPE val);
        TYPE topDynArr(DynArr *v);
        void popDynArr(DynArr *v);

     Hint: use another stack to hold elements while you search
     and then restore the initial state of `s`
  */
	for(int i=0; i<s->size; i++){
		if(s->data[i] == tofind){
			return 1;
		}
	}return 0;
}


int valid_bracket(char * str){
  /*
    str contains only bracking characters - parenthesis ( '(' and ')'
    ), square brackets ('[' and ']') and squiggly brackets ('{' and
    '}')

    This function returns 1 if str contains a set of balanced
    bracketing characters and zero otherwise.  A string is said to
    have balanced bracketing characters if each opening bracket ( '(',
    '{' and '[') contains a correspodning closing bracket
    (')','}',']') of the same type and brackets are closed in the
    reverse order that they are opened.

    For example

    valid_bracket("{}[]()") returns 1
    valid_bracket("{][}(]") returns 0, the brackets do not match
    valid_bracket("(([]))") returns 1
    valid_bracket("(([)])") returns 0,
          because the '(' at index 1 is closed by the ')' at index 3
	  before the '[' at index 2 is closed

    valid_bracket("}") returns 0 because there is no opening bracket for '{'

    valid_bracket("({}[])") returns 1
    valid_bracket("({}([]))") returns 1
    valid_bracket("({}([]){([])})") returns 1
    valid_bracket("({([]))") returns 0

  */
   	char pair;
	char temp[strlen(str)];
       	for(int i=0; i<strlen(str); i++){
		temp[i] = str[i];
	}if(strlen(str)%2 != 0)
	  	return 0; 
	for(int i=0; i<strlen(str); i++){
		if(temp[i] == '(')
	   		pair = ')';
     		else if(temp[i] == '{')
   			pair = '}';
		else if(temp[i] == '[')
   			pair = ']';
		else if(temp[i] == ')' || temp[i] == '}' || temp[i] == ']')
   			return 0;
		for(int j=strlen(str)-1; j>0; j--){
			if(temp[j]==pair){
				if( (j-i) % 2 == 0){	
				  	return 0;
				}else{
					temp[i] = '0';
					temp[j] = '0';
					break;
				}	
			} 
		} 		
	}return 1; 
}
