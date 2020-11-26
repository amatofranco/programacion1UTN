#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


/** \brief  Obtiene un nodo de la lista
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement);


LinkedList* ll_newLinkedList(void) {

	LinkedList *this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));

	if (this != NULL) {

		this->size = 0;
		this->pFirstNode = NULL;

	}
	return this;
}


int ll_len(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		returnAux = this->size;

	}
	return returnAux;
}


static Node* getNode(LinkedList *this, int nodeIndex) {

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {

		Node *pNode = NULL;

		pNode = this->pFirstNode;

		for (int i = 0; i < nodeIndex; i++) {

			pNode = pNode->pNextNode;
		}

		return pNode;

	}

	else {

		return NULL;
	}
}

Node* test_getNode(LinkedList *this, int nodeIndex) {

	return getNode(this, nodeIndex);
}


static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;

	Node *pNode = NULL;
	Node *pNodeAux = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {

		pNode = (Node*) malloc(sizeof(Node));

		if (pNode != NULL) {

			pNode->pElement = pElement;

			if (nodeIndex == 0) {

				pNode->pNextNode = this->pFirstNode;

				this->pFirstNode = pNode;

			}

			else {

				pNodeAux = getNode(this, nodeIndex - 1);

				pNode->pNextNode = pNodeAux->pNextNode;

				pNodeAux->pNextNode = pNode;

			}

			this->size++;

			returnAux = 0;

		}
	}

	return returnAux;
}


int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}


int ll_add(LinkedList *this, void *pElement) { //A diferencia de addNode, solo agrega al final (no se elige index)
	int returnAux = -1;

	if (this != NULL) {

		if (addNode(this, ll_len(this), pElement) == 0) {

			returnAux = 0;

		}
	}

	return returnAux;
}


void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;

	Node *pNode = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		pNode = getNode(this, index);

		if (pNode != NULL) {

			returnAux = pNode->pElement;
		}

	}

	return returnAux;
}


int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	Node *pNode;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		pNode = getNode(this, index);

		if (pNode != NULL) {

			pNode->pElement = pElement;

			returnAux = 0;
		}

	}

	return returnAux;
}


int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;

	Node *pNode = NULL;
	Node *pNodeAux = NULL;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		pNode = getNode(this, index);

		if (pNode != NULL) {

			if (index == 0) {

				this->pFirstNode = pNode->pNextNode;
			}

			else {

				pNodeAux = getNode(this, index - 1);

				pNodeAux->pNextNode = pNode->pNextNode;

			}

			free(pNode);

			this->size--;

			returnAux = 0;

		}
	}

	return returnAux;
}


int ll_clear(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		int len = ll_len(this);

		while (len) { // Se hace siempre en el indice 0 para no perder la referencia del next node

			ll_remove(this, 0);
			len--;
		}

		returnAux = 0;

	}

	return returnAux;
}


int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		if (ll_clear(this) == 0) {

			free(this);

			returnAux = 0;
		}

	}

	return returnAux;
}


int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {

		for (int i = 0; i < ll_len(this); i++) {

			if (ll_get(this, i) == pElement) {

				returnAux = i;
				break;

			}

		}

	}

	return returnAux;
}


int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		returnAux = 0;

		if (ll_len(this) == 0) { //returnAux = ll_len(this)? 0 : 1; (Condicional lineal)

			returnAux = 1;
		}

	}

	return returnAux;
}


int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		if (addNode(this, index, pElement) == 0) {

			returnAux = 0;
		}

	}

	return returnAux;
}


void* ll_pop(LinkedList *this, int index) {

	void *returnAux = NULL;

	void *pElement;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {

		pElement = ll_get(this, index);

		if (pElement != NULL && ll_remove(this, index) == 0) {

			returnAux = pElement;
		}
	}

	return returnAux;
}


int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {

		returnAux = 0;

		if (ll_indexOf(this, pElement) != -1) {

			returnAux = 1;
		}
	}

	return returnAux;
}


int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;

	if (this != NULL && this2 != NULL) {

		returnAux = 1;

		Node *pNode;

		for (int i = 0; i < ll_len(this2); i++) {

			pNode = (Node*) ll_get(this, i);

			if (ll_contains(this, pNode) == 0) {

				returnAux = 0;

				break;
			}

		}
	}

	return returnAux;
}

LinkedList* ll_subList(LinkedList *this, int from, int to) {

	LinkedList *cloneArray = NULL;

	Node *pNode;

	if (this != NULL && from >= 0 && from <= ll_len(this) && to >= from
			&& to <= ll_len(this)) {

		cloneArray = ll_newLinkedList();

		if (cloneArray != NULL) {

			for (int i = from; i < to; i++) {

				pNode = ll_get(this, i);

				if (pNode != NULL) {

					ll_add(cloneArray, pNode);
				}

			}

		}
	}
	return cloneArray;
}


LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;

	Node *pNode;

	if (this != NULL) {

		cloneArray = ll_newLinkedList();

		if (cloneArray != NULL) {

			for (int i = 0; i < ll_len(this); i++) {

				pNode = ll_get(this, i);

				if (pNode != NULL) {

					ll_add(cloneArray, pNode);
				}

			}

		}

	}

	return cloneArray;
}


int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	void *pElement1;
	void *pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {

		for (int i = 0; i < ll_len(this) - 1; i++) {
			for (int j = i + 1; j < ll_len(this); j++) {
				pElement1 = ll_get(this, i);
				pElement2 = ll_get(this, j);

				if ((pFunc(pElement1, pElement2) > 0 && order == 1)
						|| (pFunc(pElement1, pElement2) < 0 && order == 0)) {
					ll_set(this, i, pElement2);
					ll_set(this, j, pElement1);
				}
			}
		}
		returnAux = 0;
	}

	return returnAux;

}

LinkedList* ll_map(LinkedList *this, void (*pFunc)(void *Element)) {

	void *pElement;

	if (this != NULL && pFunc != NULL) {

		for (int i = 0; i < ll_len(this); i++) {

			pElement = ll_get(this, i);

			pFunc(pElement);

			ll_set(this, i, pElement);

		}

	}

	return this;
}


LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void *pElement)) {

	void *pElement = NULL;

	LinkedList *filteredList = NULL;

	if (this != NULL && pFunc != NULL) {

		filteredList = ll_newLinkedList();

		if (filteredList != NULL) {

			for (int i = 0; i < ll_len(this); i++) {

				pElement = ll_get(this, i);

				if(pFunc(pElement)==1){

					ll_add(filteredList,pElement);


				}

			}
		}

	}

	return filteredList;

}




int ll_count(LinkedList* this, int (*fn)(void* element)){

	int counter=-1;

	void *pElement = NULL;

	if (this != NULL && fn!=NULL) {

		        counter = 0;

				for (int i = 0; i < ll_len(this); i++) {

					pElement = ll_get(this, i);

					counter += fn(pElement);

					}

				}

	return counter;


}


