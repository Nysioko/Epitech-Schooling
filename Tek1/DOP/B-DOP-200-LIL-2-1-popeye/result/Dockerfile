FROM node:12-alpine
RUN apk update
RUN apk add bash
WORKDIR /app
COPY . /app
RUN npm install
EXPOSE 80
ENV PORT 80
CMD ["node", "server.js"]