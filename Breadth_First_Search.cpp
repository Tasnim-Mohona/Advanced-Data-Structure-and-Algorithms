Data: color[V], prev[V], d[V]
BFS(G) //Starts from here
{
    for each vertex u  V-{s}
    {
        color[u]= WHITE;
        prev[u]=NIL;
        d[u]=inf;
    }

    color[s]=GRAY;
    d[s]=0;
    prev[s]=NIL;
    Q=empty;
    ENQUEUE(Q,s);

}

While(Q not empty)
{
    u = DEQUEUE(Q);
    for each
}
