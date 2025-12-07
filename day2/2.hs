import Data.List.Split 

day2 :: IO ()
day2 = do
    contents <- readFile "./input"
    let ranges = parseLine contents

        filteredNums = [
            n | r <- ranges, 
            let [a,b] = parseRange r, 
            n <- [a..b], 
            isInvalid n
            ]

    print (sum filteredNums)

parseLine :: String -> [String]
parseLine line = splitOn "," line

parseRange :: String -> [Int]
parseRange range = map (read :: String -> Int) (splitOn "-" range)

cycleCheck :: String -> Int -> Bool
cycleCheck str substrLen 
    | substrLen <= 0 = False
    | substrLen >= length str = False
    | length str `mod` substrLen /= 0 = False
    | otherwise = (take (length str) (cycle substr)) == str
        where 
            substr = take substrLen str

isInvalid :: Int -> Bool
isInvalid x = any (cycleCheck str) [1..((length str `div` 2) + 1)]
    where
        str = show x





