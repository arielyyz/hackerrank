import Control.Applicative
import Control.Monad
import System.IO

--catalan number computing list
bs = 1 : map (\n -> sum $ zipWith (*) (reverse (take n bs)) bs) [1..]
b n = bs!!n

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    forM_ [1..n] $ \a0  -> do
        x_temp <- getLine
        let x = read x_temp :: Int
        print $ (b x) `mod` 100000007
