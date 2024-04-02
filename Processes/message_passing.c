// producer
message next_produced;

while(true) 
{
    // produce item in next_produced
    
    send(next_produced);
}

// consumer
message next_consumed;

while (true)
{
    receive(next_consumed);

    // consume item in next_consumed
}
