<img width="1206" height="3539" alt="image" src="https://github.com/user-attachments/assets/0b0bc439-5526-4da3-88b5-15aec6da5009" />Need IPC
   │
   ├── Need to share the same memory?
   │          │
   │          └── Shared Memory + Mutex/Semaphore
   │
   ├── Need to send commands/events?
   │          │
   │          └── Message Queue / D-Bus / IARM
   │
   ├── Client-Server on same machine?
   │          │
   │          └── UNIX Domain Socket
   │
   ├── Client-Server on different machines?
   │          │
   │          └── TCP Socket
   │
   └── Parent-Child simple communication?
              │
              └── Pipe


