# $FreeBSD$

PORTNAME=	tinder
PORTVERSION=	1.10.1
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby API for interfacing with Campfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-eventmachine>=1.0:devel/rubygem-eventmachine \
		rubygem-faraday>=0.9.0:www/rubygem-faraday\
		rubygem-faraday_middleware>=0.9:www/rubygem-faraday_middleware \
		rubygem-hashie>=1.0:devel/rubygem-hashie \
		rubygem-json>=1.8.0:devel/rubygem-json \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-multi_json>=1.7:devel/rubygem-multi_json \
		rubygem-twitter-stream>=0.1:net/rubygem-twitter-stream

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
