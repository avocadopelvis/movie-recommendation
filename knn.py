import pandas as pd
from sklearn.neighbors import NearestNeighbors

# load dataset
data = pd.read_csv('user.csv')

# get only ratings
X = data.iloc[:, 2:]

# set k
k = 3
knn = NearestNeighbors(n_neighbors=k)

# fit model to data
knn.fit(X)

# choose a user to find similar users for
user_index = 0
user_ratings = X.iloc[user_index, :].values.reshape(1, -1)

# find the k most similar users to the chosen user
_, indices = knn.kneighbors(user_ratings)