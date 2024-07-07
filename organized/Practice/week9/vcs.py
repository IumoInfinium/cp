for _ in range(int(input())):
    n,m,k=map(int,input().split())
    ignored_files=list(map(int,input().split()))
    tracked_files=list(map(int,input().split()))
    src_files=[i for i in range(1,n+1)]
    track_ignored=0
    for i in tracked_files:
        if i in ignored_files:
            track_ignored+=1
    untracked_files=[i for i in src_files if i not in tracked_files]
    unignored_files=[i for i in src_files if i not in ignored_files]
    untrack_unignore=0
    for i in untracked_files:
        if i in unignored_files:
            untrack_unignore+=1
    print(track_ignored,untrack_unignore)