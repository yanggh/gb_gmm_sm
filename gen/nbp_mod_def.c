#define MAX_PROTO_ID 4096
static char *ptables[4096];
#ifdef __cpluscplus
extern "C" {
#endif
void nbp_get_mod_def(char ***defs);
void nbp_get_mod_def(char ***defs) {
    ptables[101] = "application";
    ptables[800] = "gb_head";
    ptables[900] = "llc_layer";
    *defs = ptables;
}
#ifdef __cpluscplus
}
#endif
