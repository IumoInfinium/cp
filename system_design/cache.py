"""
Problem 
Have to design a cache. In which a user can insert, fetch, remove data and can also select the eviction policy during runtime. (eviction policy - protocol by which cache remove the key value pair. eg - LRU (Least Recently Used) - will remove the least used key first, TimeEviction - based upon certain time the cache will remove the key. etc)
"""

class CacheFirst:
    def __init__(self):
        print("Creating...")

    def insert(self, key, value):
        