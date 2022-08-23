# [`fract-ol`](https://github.com/willianlim/get_next_line/blob/main/pdf/en.subject.pdf)

Function should let you read the text file pointed to by the file descriptor, one line at a time.

## 📥 Installation

```bash
git clone git@github.com:willianlim/fract-ol.git
```

## ✍ Usage

```python
import foobar

# returns 'words'
foobar.pluralize('word')

# returns 'geese'
foobar.pluralize('goose')

# returns 'phenomenon'
foobar.singularize('phenomena')
```

```C
/*
	Example of main file for teste
*/

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	fd = open("file_teste.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
```


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## 📝 License
- Licença de software [`LICENSE`](https://github.com/willianlim/fract-ol/blob/master/LICENSE)
