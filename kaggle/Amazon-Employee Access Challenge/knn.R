

# a.new = 1.2
# value.b = seq(from = 0, to = 1, by = 0.001)

# pdf('MyGraphs.pdf',width=11, height=8.5,pointsize=12, paper='special')
# par(mfrow = c(3,2))

# for (i in 2:30){
#  qplot(v, dat[,i], color=factor(dat[,1]), shape=factor(dat[,1]), size=I(4))
# }
# dev.off()

setwd("C:\\Users\\simon\\Desktop\\kaggle\\Amazon-Employee Access Challenge")
library(mlbench)
library(caret) # for model tunning and selection. 
library(class) # for knn.

# Load the data from files. 
train <- read.csv('train.csv')
test <- read.csv('test.csv')

# train <- apply(train, 2, as.factor);
# test <- apply(test, 2, as.factor);
# extract the training data and class label.
for (i in 1:ncol(train)) { train[,i] <- as.factor(train[,i]) }
for (i in 1:ncol(test)) { test[,i] <- as.factor(test[,i])}

# build the knn model. 
results <- knn(train[,-1], test[,-1], cl=train[,1], k=1, prob=FALSE)

# combine the results and write to file. 
all <- cbind(1:length(results), as.vector(results))
colnames(all) <- c("Id", "Action")
write.csv(all, file="amazon-knn.csv", quote=FALSE, row.names=FALSE)

###### 
## Decision tree mining.
# Memory usage always fail.
# library(party)
#ct <- ctree(ACTION ~ ., data = train, controls=ctree_control(maxsurrogate=3))
#table(predict(ct))
#print(ct)
#plot(ct)
#plot(ct, type="simple")
#res_tree <- predict(ct, newdata=test[,-1])
#summary(res_tree)

library(rpart)
rt <- rpart(ACTION ~ ., data = train[,c(-3,-4,-5)], control=rpart.control(minSplit=10))
#plot(rt)
#text(rt, use.n=T)
rt_res <- predict(rt, newdata=test[,c(-1,-3,-4,-5)])

# Model training and tuning. 
# set.seed(1000)
# train <- train[1:300,]
# inTrain <- createDataPartition(train$ACTION, p = 0.75, list=FALSE)
# training <- train[,1:ncol(train)][inTrain, ]
# testing <- train[,1:ncol(train)][-inTrain, ]

# fitControl <- trainControl(method="repeatedcv", number=5, repeats=2)
# knnFit <- train(ACTION ~ ., data = training, method="knn", verbose=FALSE)