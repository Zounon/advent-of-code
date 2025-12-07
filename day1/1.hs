import Data.List.Split 

day2 :: IO ()
day2 = do
    contents <- readFile "./input"
    let line = lines contents
    print line
    
    -- let x = parseLine line
    -- print x
    -- ranges = parseLine line
    -- print ranges


parseLine :: String -> [String]
parseLine line = splitOn "," line

parseRange :: String -> [Int]
parseRange range = map read (splitOn "-" range) :: Int

-- subRanges :: String -> [Int]
-- subRanges




