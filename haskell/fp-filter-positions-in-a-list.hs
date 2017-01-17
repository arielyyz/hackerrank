f :: [Int] -> [Int]
f [] = []
f lst = g xs where (x:xs) = lst
g [] = []
g lst = [x] ++ f xs where (x:xs) = lst

-- This part deals with the Input and Output and can be used as it is. Do not modify it.
main = do
   inputdata <- getContents
   mapM_ (putStrLn. show). f. map read. lines $ inputdata
