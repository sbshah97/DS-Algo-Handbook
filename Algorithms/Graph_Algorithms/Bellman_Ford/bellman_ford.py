from sys import maxint
class BellmanFord( object ):
 
  def __init__( self ):
      '''
      Constructor
      '''
 
  def singleSourceShortestPath( self, weight, source ) :
    # auxiliary constants
    SIZE = len( weight )
    EVE = -1; # to indicate no predecessor
    INFINITY = maxint
 
    # declare and initialize pred to EVE and minDist to INFINITY
    pred = [EVE] * SIZE
    minDist = [INFINITY] * SIZE
 
    # set minDist[source] = 0 because source is 0 distance from itself.
    minDist[source] = 0
 
    # relax the edge set V-1 times to find all shortest paths
    for i in range( 1, SIZE - 1 ):
      for v in range( SIZE ):
        for x in self.adjacency( weight, v ):
          if minDist[x] > minDist[v] + weight[v][x]:
            minDist[x] = minDist[v] + weight[v][x]
            pred[x] = v
 
    # detect cycles if any
    for v in range( SIZE ):
      for x in self.adjacency( weight, v ):
        if minDist[x] > minDist[v] + weight[v][x]:
          raise Exception( "Negative cycle found" )
 
    return [pred, minDist]
 
 
  #=====================================================================
  # Retrieve all the neighbors of vertex v.
  #=====================================================================
  def adjacency( self, G, v ) :
    result = []
    for x in range( len( G ) ):
      if G[v][x] is not None:
        result.append( x )
 
    return result;
