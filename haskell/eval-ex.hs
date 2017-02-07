import Control.Applicative
import Control.Monad
import System.IO

fac i
    | i == 0 = 1
    | otherwise = i * fac (i-1)

e :: Double -> Double
e x = sum [ (x**i) / (fac i) | i <- [0..9] ]

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    forM_ [1..n] $ \a0  -> do
        x_temp <- getLine
        let x = read x_temp :: Double
        print (e x)
