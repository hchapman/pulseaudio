#include <stddef.h>
#include <assert.h>
#include <ltdl.h>

#include "core.h"
#include "mainloop.h"
#include "module.h"

int main(int argc, char *argv[]) {
    struct mainloop *m;
    struct core *c;
    int r;

    r = lt_dlinit();
    assert(r == 0);
    
    m = mainloop_new();
    assert(m);
    c = core_new(m);
    assert(c);

    module_load(c, "sink-pipe", NULL);
    module_load(c, "protocol-simple-tcp", NULL);
    
    mainloop_run(m);
    
    core_free(c);
    mainloop_free(m);

    lt_dlexit();
    
    return 0;
}
