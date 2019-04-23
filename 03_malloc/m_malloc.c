#include <kernel.h>

#define MY_MALLOC_SIZE 4096
static uint8_t g_malloc[MY_MALLOC_SIZE];
static int g_pos=0;

uint8_t *m_malloc(int size)
{
    int pos;
    if(size<=0 || size > MY_MALLOC_SIZE)
    {
        printk("ERROR: para error.\n");
        return NULL;
    }

    if(g_pos+size > MY_MALLOC_SIZE)
    {
        printk("ERROR: no Memery.\n");
        return NULL;
    }

    pos = g_pos;
    g_pos += size;

    return &g_malloc[pos];
}