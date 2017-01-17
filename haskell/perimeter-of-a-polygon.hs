import Control.Monad
import Data.List
import Control.Applicative ((<$>))

sqrt2 :: Int -> Double
sqrt2 x = sqrt(fromIntegral x)

readPair :: String -> (Int, Int)
readPair xs = (read w1, read w2) where [w1, w2] = words xs

perim :: Int -> [(Int, Int)] -> Double
perim 0 _ = 0
perim n ps = sqrt2 ((a - c)^2 + (b - d)^2) + perim (n-1) (tail ps) where
        (a, b) = head ps
        (c, d) = head (tail ps)

main = do
    n <- readLn :: IO Int
    input <- replicateM n (readPair <$> getLine)
    print (perim n (input ++ [head input]))
