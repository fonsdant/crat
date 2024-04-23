# C REST API Template

## Afazeres

* `linkopts = ["-lpthread"]` do libmicrohttpd.
* `--features=fully_static_link` do Containerfile.
* `bazelisk` no Containerfile.
* `sleep` (sem warning) e `strlen` (com warning) funcionam sem incluir seus cabeçalhos, respectivamente: `unistd.h` e `string.h`.
* Configurar tamanho máximo de linha para Markdown.
