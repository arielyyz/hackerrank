import Control.Monad

check :: Int -> [Int] -> Bool
check x st = dropWhile (>x) st == []

bst :: [Int] -> String
bst [] = "YES"
bst (x:xs) = if ((check x r) && (bst r) == "YES" && (bst l) == "YES") then "YES" else "NO" where 
    r = dropWhile (<x) xs
    l = takeWhile (<x) xs

main = do
    n <- readLn :: IO Int
    forM_ [1..n] $ \a0  -> do
        temp <- getLine
        input <- getLine
        putStrLn $ bst (map (read::[Char]->Int) (words input))
