data Vec = MakeVec Int Int
addVec :: Vec -> Vec -> Vec
addVec (MakeVec x1 y1) (MakeVec x2 y2) = 
  MakeVec (x1 + x2) (y1 + y2)

main :: IO()
main = do 
  l1 <- getLine
  let [a, b] = map (read::String->Int) (words l1)
  l2 <- getLine
  let [c, d] = map (read::String->Int) (words l2)
  let MakeVec m n = addVec (MakeVec a b) (MakeVec c d)
  print [m, n]
