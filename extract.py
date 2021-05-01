import pandas as pd

df = pd.read_excel('AppSpecification.xlsx', engine='openpyxl')
df = df.loc[:,~df.columns.str.match("Unnamed")]
df.dropna(subset = ["Principal"], inplace=True)
df.to_csv(r'pandas.txt', header=None, index=None, sep='\t', mode='a')