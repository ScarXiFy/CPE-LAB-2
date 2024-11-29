#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "queueDLL.h"

void initialize(Queue* queue)
{
    queue->front = NULL;
    queue->back = NULL;
}
