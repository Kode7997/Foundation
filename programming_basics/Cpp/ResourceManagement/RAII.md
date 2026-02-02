# Topic

    - RAII, smart pointers, move semantics, templates, std::atomic, memory layout

## RAII

    * Object ownership and lifetime
    * Memory ownership
    * Move semantics
    * Baseline performane measurement

    RAII Principle: 
        It is used to properly manage system resources. Objective is to _bind_ the resource to object lifetime. Meaning, allocate resource to object in constructor and release it when destructor is called. This helps managing of resources in deterministic manner to avoid leaks during exceptions.

        Scope = Automatic principle
    
    Resources:
        1. Memory (new/delete)
        2. Files (fopen/fclose)
        3. Lock (lock/unlock)
        4. Database connections
        5. Network Connections (socket)
        6. GPU Memory
        7. File descriptor
    

### Q. When do we need RAII?

    If program uses any of the system resources then RAII is applicable. This fundamental principle can be implemented manually or in some cases it implemented inherently.

    Problem:
        1. Forget to release resource
        2. Multiple exit points
        3. Exception causes leaks

### Q. How to spot Anti-RAII?

    This requires code inspection. suppose code involves creation of memeory, network socket instance, file open, database connection or file descriptors. Also if programming involves "return" statement at multple places then Anti-RAII may be seen in those places as well.

    ** File descriptor leak detection
        Before running program, note starting FD count:
            ls -1 /proc/$$/fd | wc -l

        -- Run program, then check final FD count:
            strace -e openat,open,close,dup,dup2 -o trace.log ./your_program
            grep -c openat trace.log   # opens
            grep -c 'close(' trace.log # closes

        -- Monitor live:
            watch -n 1 'ls -1 /proc/PID/fd | wc -l'  # where PID is your process ID

        -- Scan Code for Anti-RAII
            > Find manual new/delete (dangerous in modern C++)
                grep -rn '\bnew\s' src/ | grep -v '// ' | head -20
                grep -rn '\bdelete\b' src/ | grep -v '// ' | head -20

            > Find manual malloc/free
                grep -rn '\bmalloc\s*(' src/ | head -20
                grep -rn '\bfree\s*(' src/ | head -20

            > Find fopen/fclose patterns
                grep -rn 'fopen\|fclose' src/ | head -20

            > Find raw FILE* pointers (non-RAII)
                grep -rn 'FILE\s*\*' src/ | head -20

            > Find manual lock/unlock (should use lock_guard)
                grep -rn '\.lock\(\)\|\.unlock\(\)' src/ | head -20

            > Find functions with many return statements (manual cleanup nightmare)
                for f in $(find src -name '*.cpp' -o -name '*.h'); do
                lines=$(wc -l < "$f")
                returns=$(grep -c '^\s*return' "$f" 2>/dev/null || echo 0)
                if [ "$returns" -gt 5 ]; then
                    echo "$f: $returns returns in $lines lines"
                fi
                done

## RAII Classes in CPP

    Resource Type RAII Class
        Memory - std::unique_ptr<T>
        Shared Memory - std::shared_ptr<T>
        Files - std::ifstream, std::ofstream
        Mutex Lock - std::lock_guard<Mutex>
        Dynamic Arrays - std::vector<T>
        Strings - std::string

