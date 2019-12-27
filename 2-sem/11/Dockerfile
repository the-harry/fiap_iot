# Dentro do Dockerfile todas as palavras chaves são em letras maiusculas
# Começamos com o FROM, para falar qual imagem usaremos de base para nossa imagem.
FROM python:3.6

# WORKDIR é a pasta em que sua aplicação vai rodar, quase como se fosse um home
# da aplicação.
WORKDIR /app

# aqui copiamos o arquivo de requesitos da nossa máquina para o container
# como definimos um WORKDIR esse arquivo ficará em /app/requirements.txt
COPY requirements.txt requirements.txt

# Quando queremos rodar algum comando usamos o RUN, aqui atualizamos o pip e
# instalamos os requesitos da aplicação
RUN pip3 install --upgrade pip && pip3 install -r /app/requirements.txt

# Com essa imagem agora já temos o ambiente pronto para receber nossa aplicação.
