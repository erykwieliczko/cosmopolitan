/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2022 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/x/x.h"
#include "net/http/url.h"
#include "third_party/lua/cosmo.h"
#include "third_party/lua/lauxlib.h"
#include "third_party/lua/lua.h"

int LuaEncodeUrl(lua_State *L) {
  size_t size;
  struct Url h;
  int i, j, k, n, m;
  const char *data;
  if (!lua_isnil(L, 1)) {
    bzero(&h, sizeof(h));
    luaL_checktype(L, 1, LUA_TTABLE);
    if (lua_getfield(L, 1, "scheme"))
      h.scheme.p = lua_tolstring(L, -1, &h.scheme.n);
    if (lua_getfield(L, 1, "fragment"))
      h.fragment.p = lua_tolstring(L, -1, &h.fragment.n);
    if (lua_getfield(L, 1, "user")) h.user.p = lua_tolstring(L, -1, &h.user.n);
    if (lua_getfield(L, 1, "pass")) h.pass.p = lua_tolstring(L, -1, &h.pass.n);
    if (lua_getfield(L, 1, "host")) h.host.p = lua_tolstring(L, -1, &h.host.n);
    if (lua_getfield(L, 1, "port")) h.port.p = lua_tolstring(L, -1, &h.port.n);
    if (lua_getfield(L, 1, "path")) h.path.p = lua_tolstring(L, -1, &h.path.n);
    if (lua_getfield(L, 1, "params")) {
      luaL_checktype(L, -1, LUA_TTABLE);
      lua_len(L, -1);
      n = lua_tointeger(L, -1);
      for (i = -2, k = 0, j = 1; j <= n; ++j) {
        if (lua_geti(L, i--, j)) {
          luaL_checktype(L, -1, LUA_TTABLE);
          lua_len(L, -1);
          m = lua_tointeger(L, -1);
          lua_pop(L, 1);  // remove the table length
          if (m >= 1 && lua_geti(L, -1, 1)) {
            h.params.p =
                xrealloc(h.params.p, ++h.params.n * sizeof(*h.params.p));
            h.params.p[h.params.n - 1].key.p =
                lua_tolstring(L, -1, &h.params.p[h.params.n - 1].key.n);
            if (m >= 2 && lua_geti(L, -2, 2)) {
              h.params.p[h.params.n - 1].val.p =
                  lua_tolstring(L, -1, &h.params.p[h.params.n - 1].val.n);
            } else {
              h.params.p[h.params.n - 1].val.p = 0;
              h.params.p[h.params.n - 1].val.n = 0;
            }
          }
          i--;
        }
        i--;
      }
    }
    data = EncodeUrl(&h, &size);
    lua_pushlstring(L, data, size);
    free(h.params.p);
    free(data);
  } else {
    lua_pushnil(L);
  }
  return 1;
}
