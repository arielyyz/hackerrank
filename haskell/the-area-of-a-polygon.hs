import Control.Monad
import Data.List
import Control.Applicative ((<$>))

readPoint :: String -> [Double]
readPoint xs = map read $ words xs

sol :: [[Double]] -> Double
sol ps = (/2) . abs . sum $ zipWith op ps (last ps : ps)
    where
    op p q = head p * last q - last p * head q
    
main :: IO ()
main = do
    n <- readLn :: IO Int
    ps <- replicateM n (readPoint <$> getLine)
    print $ sol ps

