#ifndef form_h
#define form_h

typedef struct cad *Cadastro;

Cadastro criaLista(void);
Cadastro criaCad(char *nome, char *email, int cpf, int tel, int cep, char *log, int num, char *bairro, char *cid, char *estado);
Cadastro insereFim(Cadastro lista, char *nome, char *email, int cpf, int tel, int cep, char *log, int num, char *bairro, char *cid, char *estado);
void Listar(Cadastro lista);
Cadastro Remove(Cadastro lista, int cpf);
int Busca(Cadastro lista, int cpf);
Cadastro DestroiLista(Cadastro lista);

#endif
