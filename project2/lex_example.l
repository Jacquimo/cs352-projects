%{
    int nline;
%}

%%
\n         { nline++; }
.          ;
%%

int yywrap(void){
  return 1;
}
int main(void) {
    yylex();
    printf("%d\n", nline);
    return 0;
}
