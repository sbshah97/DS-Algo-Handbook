/*  Description: Returns the MST of a given graph. MST: Minimum Spanning Tree. It's the spanning tree with minimum weight edges between nodes.
    
    Utilities: ...

    Approaches (<complexity>):

        <O(E log(E) or E log(V))> {
            After computing an array of edges (pair<node1, pair<node2, weight>>), sort them and, in order, if their vertexs are of different subsets, get them together and insert this edge at the answer spanning tree.

            Requirements:
                * Graph in vector of edges (pair<u, pair<v, w>>) Edg;
                * int Array parent[1 ~ E];
                
                */
                bool cmp(iid a, iid b){
                    return a.second.second < b.second.second;
                }

                int findset(int x){
                    if(x != parent[x])
                        parent[x] = findset(parent[x]);
                    return parent[x];
                }

                double kruskal() {
                    list<iid> T;    //Final spanning tree
                    sort(Edg.begin(), Edg.end(), cmp);
                    int i, pu, pv;
                    double size = 0.0
                    for(int i=0; i<=Edg.size(); i++) {
                        parent[i] = i;
                    }
                    for(int i=0; i<Edg.size(); i++) {
                        pu = findset(Edg[i].first);
                        pv = findset(Edg[i].second.first);
                        if(pu!=pv){
                            T.push_back(Edg[i]); //Add edge to spanning tree;
                            size+=Edg[i].second.second;
                            parent[pu] = parent[pv];
                        }
                    }
                    return size; //return sum of all edge's weight in tree.
                }
                
/*
*/
