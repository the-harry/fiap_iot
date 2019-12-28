# Aula 13 - Introdução a monitoração com Grafana.

## Conteúdo

O Grafana é um software livre para a criação de dashboards web, ele tem muitas features bacanas nele como a fácil conexão com grande parte dos bancos de dados existentes, criação de alertas, manilupalção de dados para criar tabelas e gráficos, entre diversas coisas.
Ao instalarmos o grafana ou subirmos um container e acessarmos o endereço dele nos será solicitado um login. Entre com o login inicial que é `admin:admin`, agora antes de mais nada, precisamos entender o que é um data source.

Um data source é de onde vem nossos dados, qual a fonte que vamos pegar os dados, podem ser bancos de dados como mysql, InfluxDB, entre outros. Atualmente os datasources suportados são: AWS CloudWatch, Azure Monitor, Elasticsearch, Google Stackdriver, Graphite, InfluxDB, Loki, Microsoft SQL Server (MSSQL), Mixed, MySQL, OpenTSDB, PostgreSQL, Prometheus, Testdata.
Porém caso queira usar algum que não tenha sido listado aqui, como o mongoDB por exemplo, o grafana conta com plugins que podem nos ajudar a fazer essa conexão.

Procure no menu a opção datasources e selecione o tipo que deseja criar, coloque a URL e adicione as informaçõoes de acesso. Caso esteja tudo certo quando salvar aparecerá uma mensagem informando que o datasource funciona.
Depois de criar um datasource podemos criar nosso dashboard. A primeira coisa é escolher um tipo de visualisação, os mais usados são gráficos, tabelas, e singlestat(que mostra apenas um dado, e.g. numero de contas ativas). Porém temos outros tipos que já vem no grafana e outros que podem ser adicionados por meio de plugins, como um mapa mundi por exemplo.
Ao escolher por exemplo o gráfico, temos que selecionar qual datasource usaremos nele e ajustar as queries para pergarmos os valores que queremos.

Outra feature legal do grafana é a possibilidade de criar alertas caso alguma medição atinja certo nível. Primeiro devemos cadastrar o tipo do alerta e depois criar suas regras(alert rules). Por padrão são aceitos alertas por email, slack, discord, e muitos outros, inclusive chamadas de API, o que nos permite usar até alertas que não existiam antes no grafana, como sms.

Depois de criar e salvar tudo, uma coisa que pode ser bem útil é exportar o JSON daquela dashboard, isso nos permite reconstrui-la rapidamente, e alterar os campos de uma maneira direta. Para fazer isso abra sua dashboard e vá em settings e procure por `JSON model`. Só salvar e caso queira subir um dashboard com os mesmos datasources e alertas é só importar esse JSON.


## Desafio

### User history

Seu time deseja iniciar uma monitoração na aplicação que foi desenvolvida até agora, como na última já foi criado o banco agora vamos montar uma dashboard no grafana para facilitar a visualisação desses dados.

### Tasklist

* [ ] Criar serviço do grafana no docker-compose

* [ ] Configurar datasource do InfluxDB

* [ ] Criar alerta

* [ ] Montar dashboard

* [ ] Exportar JSON
