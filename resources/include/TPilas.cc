
//#include "TLists.cc"

#define CreateStack CreateList
#define IsemptyStack IsemptyList
#define ShowStack Showlist
#define InsertStack InsertList

#define TStack TList

TStack *TopStack(TNode *list){

    return list;
}


TStack *ExtractLIFO(TNode **list){

	TNode *p;
	if(!IsemptyList(*list)){
		p=*list;
        *list=p->prox;
        return p;
	}else{ //Si la list es vacia devolvemos un puntero null
	 	return nullptr;
    }
		   
}

TStack *ExtractFIFO(TNode **list){

	TNode *p=*list, *pAnt=nullptr, *p2Ant=nullptr;

	if(!IsemptyList(*list)){
    	while(p!=nullptr){ //Recirre la list hasta que encuentra nullptr (final)
			p2Ant=pAnt; //Guardo el puntero de 2 nodos anteriores
        	pAnt = p; //Guardo el puntero del nodo anteriore
			p=p->prox;
    	}
		p2Ant->prox=nullptr;
		return pAnt;

	}else{ //Si la list es vacia devolvemos un puntero null
	 	return nullptr;
    }	   
}

void EmptyStack(TNode **list){

	TNode *p=*list, *pAnt=nullptr;
	while(p!=nullptr){
		pAnt=p; //Guardo el nodo anterior para liberarlo
		p=p->prox;
		free(pAnt);
	}
	*list=nullptr;
}