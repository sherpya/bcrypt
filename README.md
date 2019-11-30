# Limited Windows Cryptographic Primitives Library

It's not intended for general use, but only to run FFmpeg on Windows XP.

It's implemented by wrapping deprecated wincrypt api.

`BCryptOpenAlgorithmProvider` calls `CryptAcquireContext` with hardcoded arguments,
but it's enough for `av_get_random_seed()` call that internally uses `CryptGenRandom`.

Sources: <https://github.com/sherpya/bcrypt>

```text
Copyright (C) 2019 by Gianluigi Tiesi <sherpya@netfarm.it>

Permission to use, copy, modify, and/or distribute this software
for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
```
