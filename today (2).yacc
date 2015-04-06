%left ’+’
%left ’*’
%%
E : E ’+’ E
| E ’*’ E
| ’(’ E ’)’
| ’a’
;
%%
yylex() {
int c;
while ((c=getchar()) == ’ ’);
if (c == ’\n’) return 0;
return c;
}
yyerror(char *s) {
printf("%s\n", s);
}
main() {
if (yyparse() == 0) printf("ok\n");
}