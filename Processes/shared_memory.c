# define BUFFER_SIZE 10

typedef struct{} item;

item buffer[BUFFER_SIZE]; // can only use BUFFER_SIZE - 1 elemetns
item next_produced;
item next_consumed;

int in = 0;
int out = 0;

while (true) 
{
    while (((in + 1) & BUFFER_SIZE) == out);
    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
}

while (true)
{
    while (in == out);
    next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    // consume item in next consumed    
}
