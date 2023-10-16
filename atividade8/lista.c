int lista_verificar_existencia(No* L, char valor_busca) {
    if (L == NULL) {
        return 0;
    }
    if (L->valor == valor_busca) {
        return 1;
    }
    return lista_verificar_existencia(L->proximo_no, valor_busca);
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    if (L == NULL) {
        return 0;
    }
    int ocorrencias = (L->valor == valor_busca) ? 1 : 0;
    return ocorrencias + lista_verificar_ocorrencias(L->proximo_no, valor_busca);
}


void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo_no);
    printf("%c ", L->valor);
}


void lista_inserir_no_i(No* L, int i) {
    if (L == NULL || i < 0) {
        return;
    }
    if (i == 0) {
        No* novo_no = no('N', L->proximo_no);
        L->proximo_no = novo_no;
    } else {
        lista_inserir_no_i(L->proximo_no, i - 1);
    }
}


void lista_remover_no_i(No* L, int i) {
    if (L == NULL || i < 0) {
        return;
    }
    if (i == 0 && L->proximo_no != NULL) {
        No* temp = L->proximo_no;
        L->proximo_no = L->proximo_no->proximo_no;
        free(temp);
    } else {
        lista_remover_no_i(L->proximo_no, i - 1);
    }
}


void lista_remover_no(No* L, char valor_busca) {
    if (L == NULL || L->proximo_no == NULL) {
        return;
    }
    if (L->proximo_no->valor == valor_busca) {
        No* temp = L->proximo_no;
        L->proximo_no = temp->proximo_no;
        free(temp);
        lista_remover_no(L, valor_busca);
    } else {
        lista_remover_no(L->proximo_no, valor_busca);
    }
}


