--- src/HaplohSeq.cpp.orig	2025-05-20 17:16:03 UTC
+++ src/HaplohSeq.cpp
@@ -195,14 +195,15 @@ void HaplohSeq::runBafHaplohseq(	std::string& obsType,
 	for (unsigned int i = 0; i < numParamEventStarts; i++) {
 
 		// Create thread pool
-		boost::asio::io_service ioService;
-	//	boost::asio::io_service::work work(ioService);
-		boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(ioService));
+		boost::asio::io_context ioContext;
+		auto workGuard = boost::asio::make_work_guard(ioContext);
 		boost::thread_group threadPool;
 
 		// Spawn worker threads
-		for (std::size_t t = 0; t < numThreads; t++) {
-			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
+		for (std::size_t t = 0; t < numThreads; ++t) {
+		        threadPool.create_thread([&ioContext]() {
+		                ioContext.run();
+		        });
 		}
 
 		std::map<std::string, boost::shared_ptr<Hmm> > chrHmms;
@@ -219,8 +220,7 @@ void HaplohSeq::runBafHaplohseq(	std::string& obsType,
 			chrHmms[chr] = hmmPtr;
 
 			std::cout << "Posting job to thread pool for chromosome " << chr << "\n";
-			// IMPORTANT: do not pass shared_ptr by reference because the shared_ptr expects a new pointer to the object
-			ioService.post(boost::bind(&HaplohSeq::runBafHaplohseqChr, this,
+			boost::asio::post(ioContext, boost::bind(&HaplohSeq::runBafHaplohseqChr, this,
 													chr,
 													boost::ref(chrHmms),
 													boost::ref(fp),
@@ -231,7 +231,7 @@ void HaplohSeq::runBafHaplohseq(	std::string& obsType,
 			));
 		}
 
-		work.reset();
+		workGuard.reset();
 		threadPool.join_all();	// wait for all threads to finish
 		std::cout << "Joined all thread jobs.\n";
 
@@ -413,14 +413,15 @@ void HaplohSeq::runVcfHaplohseq(	std::string& obsType,
 	for (unsigned int i = 0; i < numParamEventStarts; i++) {
 
 		// Create thread pool
-		boost::asio::io_service ioService;
-	//	boost::asio::io_service::work work(ioService);
-		boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(ioService));
+		boost::asio::io_context ioContext;
+		auto workGuard = boost::asio::make_work_guard(ioContext);
 		boost::thread_group threadPool;
 
 		// Spawn worker threads
-		for (std::size_t t = 0; t < numThreads; t++) {
-			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
+		for (std::size_t t = 0; t < numThreads; ++t) {
+		        threadPool.create_thread([&ioContext]() {
+		                ioContext.run();
+		        });
 		}
 
 		std::map<std::string, boost::shared_ptr<Hmm> > chrHmms;
@@ -438,7 +439,7 @@ void HaplohSeq::runVcfHaplohseq(	std::string& obsType,
 
 //			std::cout << "Posting job to thread pool for chromosome " << chr << "\n";
 			// IMPORTANT: do not pass shared_ptr by reference because the shared_ptr expects a new pointer to the object
-			ioService.post(boost::bind(&HaplohSeq::runVcfHaplohseqChr, this,
+			boost::asio::post(ioContext, boost::bind(&HaplohSeq::runVcfHaplohseqChr, this,
 													chr,
 													boost::ref(chrHmms),
 													boost::ref(fp),
@@ -449,7 +450,7 @@ void HaplohSeq::runVcfHaplohseq(	std::string& obsType,
 			));
 		}
 
-		work.reset();
+		workGuard.reset();
 		threadPool.join_all();	// wait for all threads to finish
 //		std::cout << "Joined all thread jobs.\n";
 
