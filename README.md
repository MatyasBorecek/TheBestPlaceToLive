## The best place to live
Imagine that you want to find the best place to live. We have straight street which is single row.

On the other side we have two types of inputs
- Types of building what we want to visit.
- The hash map of blocks where we have types of buildings.

### Example
```
reqs = ["gym", "school", "store"];
```

```
blocks = [
    {
        "gym": false,
        "school": true,
        "store": false
    },
    {
        "gym": true,
        "school": false,
        "store": false    
    },
    {
        "gym": true,
        "school": true,
        "store": false
    },
    {
        "gym": false,
        "school": true,
        "store": true
    }
];
```
In this case the best match is the third block. We have gym and school already at the block and store is in one above.