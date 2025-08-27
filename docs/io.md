# io.h

Input/output utilities.

## Functions

### `int io_puts(String msg, int stream)`
Write a string to the given stream.

- **Parameters:**
- `msg`: String to write.
- `stream`: One of `STDIN`, `STDOUT`, `STDERR`.
- **Returns:** Number of bytes written, or `-1` on error.
- **Notes:** No newline is appended. Uses the `write` syscall.

---

### `int io_gets(String* msg, int stream, int count)`
Read up to `count` bytes from `stream` into `msg`.

- **Parameters:**
- `msg`: Pointer to an existing `String` with allocated space.
- `stream`: One of `STDIN`, `STDOUT`, `STDERR`.
- `count`: Maximum number of characters to read.
- **Returns:** Number of bytes read, or `-1` on error.
- **Notes:** Caller must ensure `msg->chars` has capacity.
