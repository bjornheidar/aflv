// Author: Hjalti Leifsson

#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <sstream>

using namespace std;

#define iterate(i, a) for ( __typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define INF 123456

vector< pair<int,int> > adj[ 505 ];

int fireStation[ 105 ];

int dist[ 505 ];

void dijkstra(int start)
{
    memset( dist, -1, sizeof(dist) );

    dist[ start ] = 0;

    priority_queue< pair<int,int>,
                    vector<pair<int,int> >,
                    greater<pair<int,int> > > pq;

    pq.push( make_pair( dist[start], start ) );

    while ( !pq.empty() )
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if ( d != dist[u] ) continue;

        iterate(it, adj[u])
        {
            int w = it->first;
            int v = it->second;
            if ( dist[v]==-1 || dist[u] + w < dist[v] )
            {
                dist[ v ] = dist[u] + w;
                pq.push( make_pair( dist[v], v ) );
            }
        }
    }
}
int main()
{
    int no_of_stations, no_of_intersections;
    int u, v, weight, T;
    string str;
    cin >> T;
    while ( T-- )
    {
        cin >> no_of_stations >> no_of_intersections;

        no_of_intersections++;

        for (int i=0; i < no_of_stations; i++)
        {
            cin >> fireStation[i];
            adj[0].push_back( make_pair( 0, fireStation[i] ) );
        }

        cin.ignore();
        while(getline(cin, str))
        {
            if(str.empty())
            {
                break;
            }

            istringstream iss(str);
            iss >> u;
            iss >> v;
            iss >> weight;

            adj[ u ].push_back( make_pair( weight, v ) );
            adj[ v ].push_back( make_pair( weight, u ) );
        }

        int best_so_far = INF;

        int best_place = 1;

        for (int i = 1; i < no_of_intersections; i++)
        {
            adj[0].push_back( make_pair( 0, i ) );

            dijkstra( 0 );

            int max_dist = *max_element( dist, (dist + no_of_intersections) );

            if ( max_dist < best_so_far )
            {
                best_so_far = max_dist;
                best_place = i;
            }

            adj[0].pop_back();
        }

        cout << best_place << endl << endl;

        for (int i=0; i < no_of_intersections; i++)
        {
            adj[i].clear();
        }
    }

    return 0;
}
