Node* copy_list(Node* pHead){

    Node* pCopy = NULL;

    if(pHead == NULL){
        return NULL;
    }

    pCopy = (Node*)malloc(sizeof(Node));
    if(pCopy == NULL){
        return NULL;
    }

    pCopy->data = pHead->data;
    pCopy->next = copy_list(pHead->next)
    return pCopy;


}