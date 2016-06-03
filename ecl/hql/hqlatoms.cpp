/*##############################################################################

    HPCC SYSTEMS software Copyright (C) 2012 HPCC Systems®.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
############################################################################## */
#include "hql.hpp"
#include "hqlatoms.hpp"

IIdAtom * atId;
IIdAtom * defaultFieldNameId;
IIdAtom * failId;
IIdAtom * bindBooleanParamId;
IIdAtom * bindDataParamId;
IIdAtom * bindDatasetParamId;
IIdAtom * bindFloatParamId;
IIdAtom * bindRealParamId;
IIdAtom * bindRowParamId;
IIdAtom * bindSetParamId;
IIdAtom * bindSignedParamId;
IIdAtom * bindSignedSizeParamId;
IIdAtom * bindStringParamId;
IIdAtom * bindVStringParamId;
IIdAtom * bindUnicodeParamId;
IIdAtom * bindUnsignedParamId;
IIdAtom * bindUnsignedSizeParamId;
IIdAtom * bindUtf8ParamId;
IIdAtom * compileEmbeddedScriptId;
IIdAtom * getEmbedContextId;
IIdAtom * getBooleanResultId;
IIdAtom * getDataResultId;
IIdAtom * getDatasetResultId;
IIdAtom * getRealResultId;
IIdAtom * getRowResultId;
IIdAtom * getSetResultId;
IIdAtom * getSignedResultId;
IIdAtom * getStringResultId;
IIdAtom * getTransformResultId;
IIdAtom * getUnicodeResultId;
IIdAtom * getUnsignedResultId;
IIdAtom * getUTF8ResultId;
IIdAtom * importId;
IIdAtom * lineId;
IIdAtom * loadId;
IIdAtom * macroId;
IIdAtom * maxLengthId;
IIdAtom * maxSizeId;
IIdAtom * __optionsId;
IIdAtom * outputId;
IIdAtom * physicalLengthId;
IIdAtom * selfId;
IIdAtom * sharedId;
IIdAtom * storeId;
IIdAtom * supportsImportId;
IIdAtom * supportsScriptId;
IIdAtom * syntaxCheckId;
IIdAtom * unknownId;
IIdAtom * unnamedId;
IIdAtom * valueId;

IAtom * abstractAtom;
IAtom * accessAtom;
IAtom * actionAtom;
IAtom * activeAtom;
IAtom * activeFailureAtom;
IAtom * activeNlpAtom;
IAtom * afterAtom;
IAtom * algorithmAtom;
IAtom * _aliased_Atom;
IAtom * allAtom;
IAtom * allocatorAtom;
IAtom * alreadyVisitedAtom;
IAtom * _alreadyAssignedNestedTag_Atom;
IAtom * _alreadyVisitedMarker_Atom;
IAtom * alwaysAtom;
IAtom * _array_Atom;
IAtom * asciiAtom;
IAtom * assertAtom;
IAtom * assertConstAtom;
IAtom * atmostAtom;
IAtom * aveAtom;
IAtom * backupAtom;
IAtom * balancedAtom;
IAtom * bcdAtom;
IAtom * beforeAtom;
IAtom * bestAtom;
IAtom * bitmapAtom;
IAtom * blobAtom;
IAtom * cAtom;
IAtom * cardinalityAtom;
IAtom * caseAtom;
IAtom * checkinAtom;
IAtom * checkoutAtom;
IAtom * _childAttr_Atom;
IAtom * choosenAtom;
IAtom * clusterAtom;
IAtom * _codehash_Atom;
IAtom * _colocal_Atom;
IAtom * commonAtom;
IAtom * _complexKeyed_Atom;
IAtom * compressedAtom;
IAtom * __compressed__Atom;
IAtom * _conditionFolded_Atom;
IAtom * constAtom;
IAtom * _container_Atom;
IAtom * contextAtom;
IAtom * contextSensitiveAtom;
IAtom * costAtom;
IAtom * countAtom;
IAtom * counterAtom;
IAtom * _countProject_Atom;
IAtom * cppAtom;
IAtom * _cppBody_Atom;
IAtom * csvAtom;
IAtom * ctxmethodAtom;
IAtom * dataAtom;
IAtom * _dataset_Atom;
IAtom * debugAtom;
IAtom * dedupAtom;
IAtom * defaultAtom;
IAtom * _default_Atom;
IAtom * defineAtom;
IAtom * definitionAtom;
IAtom * deprecatedAtom;
IAtom * descAtom;
IAtom * diskAtom;
IAtom *_disallowed_Atom;
IAtom * distributedAtom;
IAtom * _distributed_Atom;
IAtom * _dot_Atom;
IAtom * dynamicAtom;
IAtom * ebcdicAtom;
IAtom * eclrtlAtom;
IAtom * embeddedAtom;
IAtom * _empty_str_Atom;
IAtom * encodingAtom;
IAtom * encryptAtom;
IAtom * ensureAtom;
IAtom * enthAtom;
IAtom * entrypointAtom;
IAtom * errorAtom;
IAtom * eventExtraAtom;
IAtom * eventNameAtom;
IAtom * exceptAtom;
IAtom * exclusiveAtom;
IAtom * expireAtom;
IAtom * exportAtom;
IAtom * extendAtom;
IAtom * externalAtom;
IAtom * failAtom;
IAtom * failCodeAtom;
IAtom * failMessageAtom;
IAtom * failureAtom;
IAtom * falseAtom;
IAtom * fastAtom;
IAtom * fewAtom;
IAtom * fieldAtom;
IAtom * fieldsAtom;
IAtom * __fileposAtom;
IAtom * filenameAtom;
IAtom * filepositionAtom;
IAtom * _files_Atom;
IAtom * filterAtom;
IAtom * filteredAtom;
IAtom * _filtered_Atom;
IAtom * firstAtom;
IAtom * firstLeftAtom;
IAtom * firstRightAtom;
IAtom * fixedAtom;
IAtom * flagAtom;
IAtom * flagsAtom;
IAtom * flatAtom;
IAtom * foldAtom;
IAtom * formatAtom;
IAtom * forwardAtom;
IAtom * fullonlyAtom;
IAtom * fullouterAtom;
IAtom * _function_Atom;
IAtom * globalContextAtom;
IAtom * gctxmethodAtom;
IAtom * getAtom;
IAtom * globalAtom;
IAtom * graphAtom;
IAtom * _graphLocal_Atom;
IAtom * groupAtom;
IAtom * groupedAtom;
IAtom * hashAtom;
IAtom * headingAtom;
IAtom * _hidden_Atom;
IAtom * hintAtom;
IAtom * holeAtom;
IAtom * holeposAtom;
IAtom * __ifblockAtom;
IAtom * ignoreAtom;
IAtom * ignoreBaseAtom;
IAtom * implementsAtom;
IAtom * _implicitFpos_Atom;
IAtom * _implicitSorted_Atom;
IAtom * importAtom;
IAtom * includeAtom;
IAtom * indeterminateAtom;
IAtom * indexAtom;
IAtom * initfunctionAtom;
IAtom * inlineAtom;
IAtom * innerAtom;
IAtom * interfaceAtom;
IAtom * internalAtom;
IAtom * _internal_Atom;
IAtom * internalFlagsAtom;
IAtom * _isFunctional_Atom;
IAtom * _isBlobInIndex_Atom;
IAtom * isNullAtom;
IAtom * isValidAtom;
IAtom * jobAtom;
IAtom * jobTempAtom;
IAtom * jsonAtom;
IAtom * keepAtom;
IAtom * keyedAtom;
IAtom * labeledAtom;
IAtom * languageAtom;
IAtom * lastAtom;
IAtom * _lazy_Atom;
IAtom * leftAtom;
IAtom * leftonlyAtom;
IAtom * leftouterAtom;
IAtom * libraryAtom;
IAtom * lightweightAtom;
IAtom * _lightweight_Atom;
IAtom * limitAtom;
IAtom * linkAtom;
IAtom * _linkCounted_Atom;
IAtom * literalAtom;
IAtom * localAtom;
IAtom * localUploadAtom;
IAtom * localeAtom;
IAtom * localFilePositionAtom;
IAtom * _location_Atom;
IAtom * logAtom;
IAtom * logicalFilenameAtom;
IAtom * lookupAtom;
IAtom * lzwAtom;
IAtom * macroAtom;
IAtom * manyAtom;
IAtom * markerAtom;
IAtom * matchedAtom;
IAtom * matchLengthAtom;
IAtom * matchPositionAtom;
IAtom * matchTextAtom;
IAtom * matchUnicodeAtom;
IAtom * matchUtf8Atom;
IAtom * maxAtom;
IAtom * maxCountAtom;
IAtom * maxLengthAtom;
IAtom * maxSizeAtom;
IAtom * mergeAtom;
IAtom * mergeTransformAtom;
IAtom * _metadata_Atom;
IAtom * methodAtom;
IAtom * minAtom;
IAtom * minimalAtom;
IAtom * memoryAtom;
IAtom * moduleAtom;
IAtom * mofnAtom;
IAtom * multipleAtom;
IAtom * nameAtom;
IAtom * namedAtom;
IAtom * namespaceAtom;
IAtom * newAtom;
IAtom * newSetAtom;
IAtom * _nlpParse_Atom;
IAtom * noBoundCheckAtom;
IAtom * noCaseAtom;
IAtom * noConstAtom;
IAtom * nofoldAtom;
IAtom * _noHoist_Atom;
IAtom * noLocalAtom;
IAtom * _nonEmpty_Atom;
IAtom * noOverwriteAtom;
IAtom * _normalized_Atom;
IAtom * noRootAtom;
IAtom * noScanAtom;
IAtom * noSortAtom;
IAtom * _noStreaming_Atom;
IAtom * notAtom;
IAtom * notMatchedAtom;
IAtom * notMatchedOnlyAtom;
IAtom * noTrimAtom;
IAtom * noTypeAtom;
IAtom * noXpathAtom;
IAtom * oldSetFormatAtom;
IAtom * omethodAtom;
IAtom * _omitted_Atom;
IAtom * onceAtom;
IAtom * onFailAtom;
IAtom * onWarningAtom;
IAtom * optAtom;
IAtom * orderedAtom;
IAtom * _ordered_Atom;
IAtom * _origin_Atom;
IAtom * _original_Atom;
IAtom * outAtom;
IAtom * outoflineAtom;
IAtom * outputAtom;
IAtom * overwriteAtom;
IAtom * ownedAtom;
IAtom * packedAtom;
IAtom * parallelAtom;
IAtom * parameterAtom;
IAtom * partitionAtom;
IAtom * partitionLeftAtom;
IAtom * partitionRightAtom;
IAtom * passParameterMetaAtom;
IAtom * _payload_Atom;
IAtom * persistAtom;
IAtom * physicalFilenameAtom;
IAtom * pluginAtom;
IAtom * prefetchAtom;
IAtom * preloadAtom;
IAtom * priorityAtom;
IAtom * privateAtom;
IAtom * _propAligned_Atom;
IAtom * _propRecordCount_Atom;
IAtom * _propSize_Atom;
IAtom * _propUnadorned_Atom;
IAtom * pseudoentrypointAtom;
IAtom * pullAtom;
IAtom * pulledAtom;
IAtom * pureAtom;
IAtom * quoteAtom;
IAtom * randomAtom;
IAtom * rangeAtom;
IAtom * rawAtom;
IAtom * recordAtom;
IAtom * recursiveAtom;
IAtom * referenceAtom;
IAtom * refreshAtom;
IAtom * _remote_Atom;
IAtom * renameAtom;
IAtom * repeatAtom;
IAtom * resizeAtom;
IAtom * _resourced_Atom;
IAtom * responseAtom;
IAtom * restartAtom;
IAtom * resultAtom;
IAtom * _results_Atom;
IAtom * retryAtom;
IAtom * rightAtom;
IAtom * rightonlyAtom;
IAtom * rightouterAtom;
IAtom * rollbackAtom;
IAtom * _root_Atom;
IAtom * rowAtom;
IAtom * _rowsid_Atom;
IAtom * rowLimitAtom;
IAtom * ruleAtom;
IAtom * saveAtom;
IAtom * scanAtom;
IAtom * scanAllAtom;
IAtom * scopeAtom;
IAtom * scopeCheckingAtom;
IAtom * scoreAtom;
IAtom * sectionAtom;
IAtom * _selectors_Atom;
IAtom * _selectorSequence_Atom;
IAtom * selfAtom;
IAtom * separatorAtom;
IAtom * escapeAtom;
IAtom * sequenceAtom;
IAtom * _sequence_Atom;
IAtom * sequentialAtom;
IAtom * serializationAtom;
IAtom * setAtom;
IAtom * sharedAtom;
IAtom * shutdownAtom;
IAtom * _sideEffect_Atom;
IAtom * singleAtom;
IAtom * sizeAtom;
IAtom * sizeofAtom;
IAtom * skewAtom;
IAtom * skipAtom;
IAtom * smartAtom;
IAtom * snapshotAtom;
IAtom * soapActionAtom;
IAtom * httpHeaderAtom;
IAtom * prototypeAtom;
IAtom * proxyAddressAtom;
IAtom * sampleAtom;
IAtom * sort_AllAtom;
IAtom * sort_KeyedAtom;
IAtom * sortedAtom;
IAtom * sourceAtom;
IAtom * spillAtom;
IAtom * stableAtom;
IAtom * _state_Atom;
IAtom * steppedAtom;
IAtom * storedAtom;
IAtom * storedFieldFormatAtom;
IAtom * streamedAtom;
IAtom * _streaming_Atom;
IAtom * successAtom;
IAtom * sysAtom;
IAtom * tempAtom;
IAtom * templateAtom;
IAtom * terminateAtom;
IAtom * terminatorAtom;
IAtom * thorAtom;
IAtom * thresholdAtom;
IAtom * timeoutAtom;
IAtom * timeLimitAtom;
IAtom * timestampAtom;
IAtom * tinyAtom;
IAtom * trimAtom;
IAtom * trueAtom;
IAtom * tomitaAtom;
IAtom * topAtom;
IAtom * traceAtom;
IAtom * typeAtom;
IAtom * _uid_Atom;
IAtom * unknownAtom;
IAtom * unknownSizeFieldAtom;
IAtom * unicodeAtom;
IAtom * unsortedAtom;
IAtom * unstableAtom;
IAtom * updateAtom;
IAtom * userMatchFunctionAtom;
IAtom * versionAtom;
IAtom * virtualAtom;
IAtom * _virtualSeq_Atom;
IAtom * volatileAtom;
IAtom * warningAtom;
IAtom * webserviceAtom;
IAtom * wholeAtom;
IAtom * widthAtom;
IAtom * wipeAtom;
IAtom * _workflow_Atom;
IAtom * _workflowPersist_Atom;
IAtom * workunitAtom;
IAtom * wuidAtom;
IAtom * xmlAtom;
IAtom * xmlDefaultAtom;
IAtom * xmlnsAtom;
IAtom * _xmlParse_Atom;
IAtom * xpathAtom;

#define MAKEID(x)   x##Id = createIdAtom(#x)
#define MAKEATOM(x) x##Atom = createLowerCaseAtom(#x)

#define MAKESYSATOM(x)  _##x##_Atom = createLowerCaseAtom("$_" #x "_")

MODULE_INIT(INIT_PRIORITY_HQLATOM)
{
    MAKEID(at);
    MAKEID(bindBooleanParam);
    MAKEID(bindDataParam);
    MAKEID(bindDatasetParam);
    MAKEID(bindFloatParam);
    MAKEID(bindRealParam);
    MAKEID(bindRowParam);
    MAKEID(bindSetParam);
    MAKEID(bindSignedParam);
    MAKEID(bindSignedSizeParam);
    MAKEID(bindStringParam);
    MAKEID(bindVStringParam);
    MAKEID(bindUnicodeParam);
    MAKEID(bindUnsignedParam);
    MAKEID(bindUnsignedSizeParam);
    MAKEID(bindUtf8Param);
    MAKEID(compileEmbeddedScript);
    defaultFieldNameId = createIdAtom("__f1__");
    MAKEID(fail);
    MAKEID(getEmbedContext);
    MAKEID(getBooleanResult);
    MAKEID(getDataResult);
    MAKEID(getDatasetResult);
    MAKEID(getRealResult);
    MAKEID(getRowResult);
    MAKEID(getSetResult);
    MAKEID(getSignedResult);
    MAKEID(getStringResult);
    MAKEID(getTransformResult);
    MAKEID(getUnicodeResult);
    MAKEID(getUnsignedResult);
    MAKEID(getUTF8Result);
    MAKEID(import);
    MAKEID(line);
    MAKEID(load);
    MAKEID(macro);
    MAKEID(maxLength);
    MAKEID(maxSize);
    MAKEID(__options);
    MAKEID(output);
    MAKEID(physicalLength);
    MAKEID(self);
    MAKEID(shared);
    MAKEID(store);
    MAKEID(supportsImport);
    MAKEID(supportsScript);
    MAKEID(syntaxCheck);
    MAKEID(unknown);
    unnamedId = createIdAtom("<unnamed>");
    MAKEID(value);

    MAKEATOM(abstract);
    MAKEATOM(access);
    MAKEATOM(action);
    MAKEATOM(active);
    MAKEATOM(activeFailure);
    MAKEATOM(activeNlp);
    MAKEATOM(after);
    MAKEATOM(algorithm);
    MAKESYSATOM(aliased);
    MAKEATOM(all);
    MAKEATOM(allocator);
    MAKEATOM(alreadyVisited);
    MAKESYSATOM(alreadyAssignedNestedTag);
    MAKESYSATOM(alreadyVisitedMarker);
    MAKEATOM(always);
    MAKEATOM(_array_);
    MAKEATOM(ascii);
    MAKEATOM(assert);
    MAKEATOM(assertConst);
    MAKEATOM(atmost);
    MAKEATOM(ave);
    MAKEATOM(backup);
    MAKEATOM(balanced);
    MAKEATOM(bcd);
    MAKEATOM(before);
    MAKEATOM(best);
    MAKEATOM(bitmap);
    MAKEATOM(blob);
    MAKEATOM(c);
    MAKEATOM(cardinality);
    MAKEATOM(case);
    MAKEATOM(checkin);
    MAKEATOM(checkout);
    MAKESYSATOM(childAttr);
    MAKEATOM(choosen);
    MAKEATOM(cluster);
    MAKESYSATOM(codehash);
    MAKESYSATOM(colocal);
    MAKEATOM(common);
    MAKESYSATOM(complexKeyed);
    MAKEATOM(compressed);
    MAKEATOM(__compressed__);
    MAKESYSATOM(conditionFolded);
    MAKEATOM(const);
    MAKESYSATOM(container);
    MAKEATOM(context);
    MAKEATOM(contextSensitive);
    MAKEATOM(cost);
    MAKEATOM(count);
    MAKEATOM(counter);
    MAKESYSATOM(countProject);
    MAKEATOM(cpp);
    MAKESYSATOM(cppBody);
    MAKEATOM(csv);
    MAKEATOM(ctxmethod);
    MAKEATOM(data);
    MAKESYSATOM(dataset);
    MAKEATOM(debug);
    MAKEATOM(dedup);
    MAKEATOM(default);
    MAKESYSATOM(default);
    MAKEATOM(define);
    MAKEATOM(definition);
    MAKEATOM(deprecated);
    MAKEATOM(desc);
    MAKESYSATOM(disallowed);
    MAKEATOM(disk);
    MAKEATOM(distributed);
    MAKESYSATOM(distributed);
    MAKESYSATOM(dot);
    MAKEATOM(dynamic);
    MAKEATOM(ebcdic);
    MAKEATOM(eclrtl);
    MAKEATOM(embedded);
    _empty_str_Atom = createAtom("");
    MAKEATOM(encoding);
    MAKEATOM(encrypt);
    MAKEATOM(ensure);
    MAKEATOM(enth);
    MAKEATOM(entrypoint);
    MAKEATOM(error);
    MAKEATOM(eventExtra);
    MAKEATOM(eventName);
    MAKEATOM(except);
    MAKEATOM(exclusive);
    MAKEATOM(expire);
    MAKEATOM(export);
    MAKEATOM(extend);
    MAKEATOM(external);
    MAKEATOM(fail);
    MAKEATOM(failure);
    MAKEATOM(failCode);
    MAKEATOM(failMessage);
    MAKEATOM(false);
    MAKEATOM(fast);
    MAKEATOM(few);
    MAKEATOM(field);
    MAKEATOM(fields);
    MAKEATOM(filename);
    MAKEATOM(__filepos);
    MAKEATOM(fileposition);
    MAKESYSATOM(files);
    MAKEATOM(filter);
    MAKEATOM(filtered);
    MAKESYSATOM(filtered);
    MAKEATOM(first);
    MAKEATOM(firstLeft);
    MAKEATOM(firstRight);
    MAKEATOM(fixed);
    MAKEATOM(flag);
    MAKEATOM(flags);
    MAKEATOM(flat);
    MAKEATOM(fold);
    MAKEATOM(format);
    MAKEATOM(forward);
    fullonlyAtom = createLowerCaseAtom("full only");        // different to get the ECL regeneration correct..
    fullouterAtom = createLowerCaseAtom("full outer");
    MAKESYSATOM(function);
    MAKEATOM(gctxmethod);
    MAKEATOM(get);
    MAKEATOM(global);
    MAKEATOM(globalContext);
    MAKEATOM(graph);
    MAKESYSATOM(graphLocal);
    MAKEATOM(group);
    MAKEATOM(grouped);
    MAKEATOM(hash);
    MAKEATOM(heading);
    MAKESYSATOM(hidden);
    MAKEATOM(hint);
    MAKEATOM(hole);
    MAKEATOM(holepos);
    MAKEATOM(httpHeader);
    MAKEATOM(__ifblock);
    MAKEATOM(ignore);
    MAKEATOM(ignoreBase);
    MAKEATOM(implements);
    MAKESYSATOM(implicitFpos);
    MAKESYSATOM(implicitSorted);
    MAKEATOM(import);
    MAKEATOM(include);
    MAKEATOM(index);
    MAKEATOM(indeterminate);
    MAKEATOM(initfunction);
    MAKEATOM(inline);
    MAKEATOM(inner);
    MAKEATOM(interface);
    MAKEATOM(internal);
    MAKESYSATOM(internal);
    MAKEATOM(internalFlags);
    MAKESYSATOM(isBlobInIndex);
    MAKESYSATOM(isFunctional);
    MAKEATOM(isNull);
    MAKEATOM(isValid);
    MAKEATOM(job);
    MAKEATOM(jobTemp);
    MAKEATOM(json);
    MAKEATOM(keep);
    MAKEATOM(keyed);
    MAKEATOM(labeled);
    MAKEATOM(language);
    MAKEATOM(last);
    MAKESYSATOM(lazy);
    MAKEATOM(left);
    leftonlyAtom = createLowerCaseAtom("left only");
    leftouterAtom = createLowerCaseAtom("left outer");
    MAKEATOM(library);
    MAKEATOM(lightweight);
    MAKESYSATOM(lightweight);
    MAKEATOM(limit);
    MAKEATOM(link);
    MAKESYSATOM(linkCounted);
    MAKEATOM(literal);
    MAKEATOM(local);
    MAKEATOM(localUpload);
    MAKEATOM(locale);
    MAKEATOM(localFilePosition);
    MAKESYSATOM(location);
    MAKEATOM(log);
    MAKEATOM(logicalFilename);
    MAKEATOM(lookup);
    MAKEATOM(lzw);
    MAKEATOM(macro);
    MAKEATOM(many);
    MAKEATOM(marker);
    MAKEATOM(matched);
    MAKEATOM(matchLength);
    MAKEATOM(matchPosition);
    MAKEATOM(matchText);
    MAKEATOM(matchUnicode);
    MAKEATOM(matchUtf8);
    MAKEATOM(max);
    MAKEATOM(maxCount);
    MAKEATOM(maxLength);
    MAKEATOM(maxSize);
    MAKEATOM(memory);
    MAKEATOM(merge);
    MAKEATOM(mergeTransform);
    MAKESYSATOM(metadata);
    MAKEATOM(method);
    MAKEATOM(min);
    MAKEATOM(minimal);
    MAKEATOM(module);
    MAKEATOM(mofn);
    MAKEATOM(multiple);
    MAKEATOM(name);
    MAKEATOM(named);
    MAKEATOM(namespace);
    MAKEATOM(new);
    MAKEATOM(newSet);
    MAKESYSATOM(nlpParse);
    MAKEATOM(noBoundCheck);
    MAKEATOM(noCase);
    MAKEATOM(noConst);
    MAKEATOM(nofold);
    MAKESYSATOM(noHoist);
    MAKEATOM(noLocal);
    MAKESYSATOM(nonEmpty);
    MAKEATOM(noOverwrite);
    MAKESYSATOM(normalized);
    MAKEATOM(noRoot);
    MAKEATOM(noScan);
    MAKEATOM(noSort);
    MAKESYSATOM(noStreaming);
    MAKEATOM(not);
    notMatchedAtom = createLowerCaseAtom("NOT MATCHED");
    notMatchedOnlyAtom = createLowerCaseAtom("NOT MATCHED ONLY");
    MAKEATOM(noTrim);
    MAKEATOM(noType);
    MAKEATOM(noXpath);
    MAKEATOM(oldSetFormat);
    MAKEATOM(omethod);
    MAKESYSATOM(omitted);
    MAKEATOM(once);
    MAKEATOM(onFail);
    MAKEATOM(onWarning);
    MAKEATOM(opt);
    MAKEATOM(ordered);
    MAKESYSATOM(ordered);
    MAKESYSATOM(origin);
    MAKESYSATOM(original);
    MAKEATOM(out);
    MAKEATOM(outofline);
    MAKEATOM(output);
    MAKEATOM(overwrite);
    MAKEATOM(owned);
    MAKEATOM(packed);
    MAKEATOM(parallel);
    MAKEATOM(parameter);
    MAKEATOM(partition);
    partitionLeftAtom = createLowerCaseAtom("partition left");
    partitionRightAtom = createLowerCaseAtom("partition right");
    MAKEATOM(passParameterMeta);
    MAKESYSATOM(payload);
    MAKEATOM(persist);
    MAKEATOM(physicalFilename);
    MAKEATOM(plugin);
    MAKEATOM(prefetch);
    MAKEATOM(preload);
    MAKEATOM(priority);
    MAKEATOM(private);
    MAKESYSATOM(propAligned);
    MAKESYSATOM(propRecordCount);
    MAKESYSATOM(propSize);
    MAKESYSATOM(propUnadorned);
    MAKEATOM(prototype);
    MAKEATOM(proxyAddress);
    MAKEATOM(pseudoentrypoint);
    MAKEATOM(pull);
    MAKEATOM(pulled);
    MAKEATOM(pure);
    MAKEATOM(quote);
    MAKEATOM(random);
    MAKEATOM(range);
    MAKEATOM(raw);
    MAKEATOM(record);
    MAKEATOM(recursive);
    MAKEATOM(reference);
    MAKEATOM(refresh);
    MAKESYSATOM(remote);
    MAKEATOM(rename);
    MAKEATOM(repeat);
    MAKEATOM(resize);
    MAKESYSATOM(resourced);
    MAKEATOM(response);
    MAKEATOM(restart);
    MAKEATOM(result);
    MAKESYSATOM(results);
    MAKEATOM(retry);
    MAKEATOM(right);
    rightonlyAtom = createLowerCaseAtom("right only");
    rightouterAtom = createLowerCaseAtom("right outer");
    MAKEATOM(rollback);
    MAKESYSATOM(root);
    MAKEATOM(row);
    MAKESYSATOM(rowsid);
    MAKEATOM(rowLimit);
    MAKEATOM(rule);
    MAKEATOM(sample);
    MAKEATOM(save);
    MAKEATOM(scan);
    MAKEATOM(scanAll);
    MAKEATOM(scope);
    MAKEATOM(scopeChecking);
    MAKEATOM(score);
    MAKEATOM(section);
    MAKESYSATOM(selectors);
    MAKESYSATOM(selectorSequence);
    MAKEATOM(self);
    MAKEATOM(separator);
    MAKEATOM(sequence);
    MAKESYSATOM(sequence);
    MAKEATOM(sequential);
    MAKEATOM(serialization);
    MAKEATOM(set);
    MAKEATOM(shared);
    MAKEATOM(shutdown);
    MAKESYSATOM(sideEffect);
    MAKEATOM(single);
    MAKEATOM(size);
    MAKEATOM(sizeof);
    MAKEATOM(skew);
    MAKEATOM(skip);
    MAKEATOM(smart);
    MAKEATOM(snapshot);
    MAKEATOM(soapAction);
    sort_AllAtom = createLowerCaseAtom("SORT ALL");
    sort_KeyedAtom = createLowerCaseAtom("SORT KEYED");
    MAKEATOM(sorted);
    MAKEATOM(source);
    MAKEATOM(spill);
    MAKEATOM(stable);
    MAKESYSATOM(state);
    MAKEATOM(stepped);
    MAKEATOM(stored);
    MAKEATOM(storedFieldFormat);
    MAKEATOM(streamed);
    MAKESYSATOM(streaming);
    MAKEATOM(success);
    MAKEATOM(sys);
    MAKEATOM(temp);
    MAKEATOM(template);
    MAKEATOM(terminate);
    MAKEATOM(terminator);
    MAKEATOM(escape);
    MAKEATOM(thor);
    MAKEATOM(threshold);
    MAKEATOM(timeout);
    MAKEATOM(timeLimit);
    MAKEATOM(timestamp);
    MAKEATOM(tiny);
    MAKEATOM(tomita);
    MAKEATOM(top);
    MAKEATOM(trace);
    MAKEATOM(trim);
    MAKEATOM(true);
    MAKEATOM(type);
    MAKESYSATOM(uid);
    MAKEATOM(unknown);
    MAKEATOM(unknownSizeField);
    MAKEATOM(unicode);
    MAKEATOM(unsorted);
    MAKEATOM(unstable);
    MAKEATOM(update);
    MAKEATOM(userMatchFunction);
    MAKEATOM(version);
    MAKEATOM(virtual);
    MAKESYSATOM(virtualSeq);
    MAKEATOM(volatile);
    MAKEATOM(warning);
    MAKEATOM(webservice);
    MAKEATOM(whole);
    MAKEATOM(width);
    MAKEATOM(wipe);
    MAKESYSATOM(workflow);
    MAKESYSATOM(workflowPersist);
    MAKEATOM(workunit);
    MAKEATOM(wuid);
    MAKEATOM(xml);
    MAKEATOM(xmlDefault);
    MAKEATOM(xmlns);
    MAKESYSATOM(xmlParse);
    MAKEATOM(xpath);

    return true;
}
