library("ggplot2")

#setwd('c:/Users/simon/Dropbox/Min\'s/')
setwd('/home/ada/Desktop/Dropbox/Min\'s/');

# Read in data and do basic manipulations.
dato <- read.csv('Min\'s Project-training.csv', header=FALSE)
datx <- data.frame(dato[,1:2])

dat <- dato[,3:37];
dat <- t.data.frame(dat);
colnames(dat)[1] <- 'Result'

# scatter plot. 
v = c(1:15, 1:20); 
#pdf("plots.pdf")
for (i in 301:301) {
  p <- qplot(v, as.numeric(dat[,i]), color=factor(dat[,1]), 
             shape=factor(dat[,1]), size=I(4), fill=factor(dat[,1]));
  # p <- p + scale_shape_manual(values=c(21,22))
  # p <- p + scale_color_manual(values=c("red","blue"))
  p <- p + scale_fill_discrete("group") 
  #p <- p + scale_fill_manual(name="Group")
  p <- p + scale_x_continuous(name="Sample")
  p <- p + scale_y_continuous(name=toString(datx[i,1]))
  #p <- p + scale_y_discrete(name=c(toString(datx[i,1])))
  print(p)

  }

#dev.off()
