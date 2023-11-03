import pandas as pd
import numpy as np


df = pd.DataFrame(np.random.randint(0, 100, size=(50, 3)), columns=['Column 1', 'Column 2', 'Column 3'])
mask = np.random.choice([True, False], size=df.shape, p=[0.1, 0.9])

# Apply the mask to the dataframe
df = df.mask(mask)
# print(df)
# (a)
# Generate a boolean mask indicating which cells contain null values
mask = df.isnull()

# Count the number of null values in each column
column_null_counts = mask.sum()

# Count the number of null values in each row
row_null_counts = mask.sum(axis=1)

# Display the results
print(f"Number of null values per column:\n{column_null_counts}\n")
print(f"Number of null values per row:\n{row_null_counts}")


# (b)
# Generate a boolean mask indicating which cells contain null values
# mask = df.isnull()

# # Count the number of null values in each column
# column_null_counts = mask.sum()

# # Filter out the columns that have more than 5 null values
# columns_to_drop = column_null_counts[column_null_counts > 5].index
# df = df.drop(columns_to_drop, axis=1)
# print(df)

# (c)
# Get the index of the row with the maximum sum of all values
# max_sum_row_index = df.sum(axis=1).idxmax()

# Drop the row with the maximum sum of all values
# df = df.drop(max_sum_row_index)
# print(df)

# (d)
# Sort the dataframe on the basis of the first column
# df = df.sort_values(by='Column 1')
# print(df)

# (f) 
# covariance = df['Column 2'].cov(df['Column 3'])
# print("Covariance: ", covariance)

# (e)
# df = df.drop_duplicates(subset=['Column 1'], keep='first')
# print(df)

# (g)
# Discretize the second column into 5 bins
# df['Column 2'] = pd.cut(df['Column 2'], bins=5)
# print(df)