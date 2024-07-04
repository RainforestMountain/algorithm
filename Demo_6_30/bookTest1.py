import numpy as np
import pandas as pd

x = pd.Series([1, 3, 5, np.nan])

dates = pd.date_range(start='20200101', end='20201231', freq='D')
print(dates)
dates = pd.date_range(start='20200101', end='20201231', freq='M')
print(dates)

df = pd.DataFrame(np.random.randn(12, 4), index=dates, columns=list('ABCD'))
print(df)
df = pd.DataFrame([[np.random.randint(1, 100) for j in range(4)] for i in range(12)], index=dates, columns=list('ABCD'))
print(df)
df = pd.DataFrame({'A': [np.random.randint(1, 100) for i in range(4)]
                      , 'B': pd.date_range(start='20200101', periods=4, freq='D')})

print(df)

print(df.head())
print(df.head(3))
print(df.tail(1))
